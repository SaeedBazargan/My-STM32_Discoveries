#include "cmsis_os.h"
#include "lwip/opt.h"
#include "lwip/api.h"
#include "lwip/sys.h"

#include "udpclient.h"
#include "string.h"

static struct netconn *conn;
static struct netbuf *rxbuf;

int indx = 0;
char responseMsg[200];

static void udpinit_thread(void *arg)
{
	err_t err;
	ip_addr_t dest_addr;

	conn = netconn_new(NETCONN_UDP);
	if (conn != NULL)
	{
		err = netconn_bind(conn, IP_ADDR_ANY, 7);
		if (err == ERR_OK)
		{
			IP_ADDR4(&dest_addr, 192, 168, 123, 102);
			err = netconn_connect(conn, &dest_addr, 8);
			if (err == ERR_OK)
			{
				for (;;)
				{
					err = netconn_recv(conn, &rxbuf);
					if (err == ERR_OK)
					{
						sprintf(responseMsg, "\"%s\" was sent by the Server\n", (char *)rxbuf->p->payload);
						udpsend(responseMsg);
						netbuf_delete(rxbuf);
					}
				}
			}
		}
	}
	else
	{
		netconn_delete(conn);
	}
}

void udpclient_init(void)
{
	sys_thread_new("udpinit_thread", udpinit_thread, NULL, DEFAULT_THREAD_STACKSIZE, osPriorityNormal);
}

void udpsend(char *data)
{
	struct netbuf *buf;

	buf = netbuf_new();
	netbuf_ref(buf, data, strlen(data));
	netconn_send(conn, buf);
	netbuf_delete(buf);
}


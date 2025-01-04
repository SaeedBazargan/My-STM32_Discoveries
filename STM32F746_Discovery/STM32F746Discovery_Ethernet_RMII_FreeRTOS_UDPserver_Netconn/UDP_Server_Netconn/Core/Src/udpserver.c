#include "lwip/opt.h"
#include "lwip/api.h"
#include "lwip/sys.h"
#include "udpserver.h"
#include "string.h"

#define MSG_LEN 100 // Maximum message length

static struct netconn *conn;
static struct netbuf *buf;

static char msg[MSG_LEN];
static char responseMsg[MSG_LEN + 50];

// UDP Server thread
static void udp_thread(void *arg)
{
    err_t err;
    struct pbuf *responseBuf;

    // Create a new UDP connection
    conn = netconn_new(NETCONN_UDP);
    if (conn == NULL) {
        return; // Exit if connection creation fails
    }

    // Bind the connection to port 7
    err = netconn_bind(conn, IP_ADDR_ANY, 7);
    if (err != ERR_OK) {
        netconn_delete(conn);
        return; // Exit if binding fails
    }

    // Main server loop
    while (1) {
        // Wait to receive data
        err = netconn_recv(conn, &buf);
        if (err == ERR_OK) {
            // Extract client information
            ip_addr_t *addr = netbuf_fromaddr(buf);   // Client IP address
            unsigned short port = netbuf_fromport(buf); // Client port

            // Copy client data to msg buffer
            strncpy(msg, buf->p->payload, MSG_LEN);
            msg[MSG_LEN - 1] = '\0'; // Ensure null termination

            // Format the response message
            int responseLen = snprintf(responseMsg, sizeof(responseMsg), "\"%s\" was sent by the Client\n", msg);

            // Allocate memory for the response buffer
            responseBuf = pbuf_alloc(PBUF_TRANSPORT, responseLen, PBUF_RAM);
            if (responseBuf != NULL) {
                // Copy response message into the buffer
                pbuf_take(responseBuf, responseMsg, responseLen);

                // Attach the response buffer to the network buffer
                buf->p = responseBuf;

                // Send response to the client
                netconn_connect(conn, addr, port);
                netconn_send(conn, buf);

                // Clean up resources
                pbuf_free(responseBuf);
                netbuf_delete(buf);
            } else {
                // Clean up resources if response buffer allocation fails
                netbuf_delete(buf);
            }
        }
    }
}

// Initialize UDP server
void udpserver_init(void)
{
    sys_thread_new("udp_thread", udp_thread, NULL, DEFAULT_THREAD_STACKSIZE, osPriorityNormal);
}

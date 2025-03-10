#include "lwip/opt.h"
#include "lwip/api.h"
#include "lwip/sys.h"

#include "tcpserver.h"
#include "string.h"

#define MSG_LEN 100   // Maximum length for the received message

static struct netconn *conn, *newconn; 			// Connection objects
static struct netbuf *buf;             			// Buffer for incoming data
char msg[MSG_LEN];                     			// Buffer to store the received message
char responseMsg[MSG_LEN + 50];               	// Buffer for the response message

/**** Handle client connections and send responses ****/
static void tcp_thread(void *arg)
{
    err_t err, accept_err;

    // Create a new TCP connection
    conn = netconn_new(NETCONN_TCP);
    if (conn == NULL)
    {
        return;		// If connection creation fails, exit the thread
    }

    // Bind the connection to the port number 7
    err = netconn_bind(conn, IP_ADDR_ANY, 7);
    if (err != ERR_OK)
    {
        netconn_delete(conn); // Cleanup if binding fails
        return;
    }

    // Set the connection to listening mode
    netconn_listen(conn);

    while (1)
    {
        // Accept new client connections
        accept_err = netconn_accept(conn, &newconn);
        if (accept_err == ERR_OK)
        {
            // Process the new connection
            while (netconn_recv(newconn, &buf) == ERR_OK)
            {
                // Process received data
                do
                {
                    // Copy the received message into the `msg` buffer
                    strncpy(msg, (char *)buf->p->payload, buf->p->len);
                    msg[buf->p->len] = '\0'; // Null-terminate the string

                    // Create a response message
                    int len = snprintf(responseMsg, (MSG_LEN + 50), "\"%s\" was sent by the Server\n", msg);

                    // Send the response message to the client
                    netconn_write(newconn, responseMsg, len, NETCONN_COPY);

                    // Clear the message buffer for the next iteration
                    memset(msg, '\0', MSG_LEN);

                } while (netbuf_next(buf) >= 0);

                // Free the netbuf after processing
                netbuf_delete(buf);
            }

            // Close and delete the connection after finishing
            netconn_close(newconn);
            netconn_delete(newconn);
        }
    }

    // Cleanup the server connection if the loop exits (unlikely in normal operation)
    netconn_delete(conn);
}

/**** Initialize the TCP server ****/
void tcpserver_init(void)
{
    // Create a new thread for the TCP server
    sys_thread_new("tcp_thread", tcp_thread, NULL, DEFAULT_THREAD_STACKSIZE, osPriorityNormal);
}

import socket

# Server IP and port
server_ip = "192.168.1.3"
server_port = 39190

# Create a TCP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    # Bind the socket to the server IP and port
    server_socket.bind((server_ip, server_port))

    # Listen for incoming connections
    server_socket.listen(1)
    print("Server listening on {}:{}".format(server_ip, server_port))

    while True:
        # Accept a client connection
        client_socket, client_address = server_socket.accept()
        print("Client connected:", client_address)

        # Handle client requests here
        # ...

        # Close the client connection
        client_socket.close()

except OSError as e:
    print("Failed to start the server:", str(e))
finally:
    # Close the server socket
    server_socket.close()
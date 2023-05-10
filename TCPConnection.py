import socket
import binascii

# Server IP and port
server_ip = "127.0.0.1"
server_port = 39190

# Create a TCP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    # Connect to the server
    client_socket.connect((server_ip, server_port))
    print("Connected to server")

    while True:
        # Receive data from the server
        data = client_socket.recv(1024)

        if not data:
            # If no more data is received, the server has closed the connection
            print("Server closed the connection")
            break

        # Print the received packet in hexadecimal format with spaces between each byte
        hex_data = " ".join([hex(byte)[2:].zfill(2) for byte in data])
        print("Received (Hex):", hex_data)

        packet = b"123456"
        client_socket.send(packet)
        print("Replied packet:", packet)

except ConnectionRefusedError:
    print("Connection refused. Make sure the server is running.")
finally:
    # Close the socket
    client_socket.close()
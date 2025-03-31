import serial
import socket
import threading

# === Teensy Serial Port ===
teensy = serial.Serial('COM3', 115200)  # replace with actual COM port

# === Network Server (listen for commands from laptop) ===
host = '0.0.0.0'
port = 6969

def handle_client(conn):
    while True:
        try:
            data = conn.recv(1024).decode().strip()
            if not data:
                break

            print(f"[RECEIVED] {data}")
            teensy.write((data + '\n').encode())  # send to Teensy

        except Exception as e:
            print(f"[ERROR] {e}")
            break
    conn.close()

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((host, port))
    server.listen(1)
    print(f"[WAITING] Listening on port {port}")
    while True:
        conn, addr = server.accept()
        print(f"[CONNECTED] From {addr}")
        client_thread = threading.Thread(target=handle_client, args=(conn,))
        client_thread.start()

start_server()

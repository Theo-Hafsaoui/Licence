import http.server
import cgi
import http.server,cgitb
cgitb.enable()
PORT = 8887
server_address = ("127.0.0.1", PORT)
server = http.server.HTTPServer
handler = http.server.CGIHTTPRequestHandler
handler.cgi_directories = ["/"]
print("Serveur actif sur le port :", PORT)
httpd = server(server_address, handler)
httpd.serve_forever()
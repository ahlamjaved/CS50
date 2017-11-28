from http.server import BaseHTTPRequestHandler, HTTPServer

# HTTPRequestHandler class
class HTTPServer_RequestHandler(BaseHTTPRequestHandler):

    # GET
    def do_GET(self):
        # send response status code
        self.send_response(200)

        # send headers
        self.send_header('Content-type','text/html')
        self.end_headers()

        # determine message to send to client
        if self.path == "/":
            message = "Hello, world!"
        else:
            name = self.path[1:]
            message = "Hello, {}!".format(name)

        # write message
        self.wfile.write(bytes(message, "utf8"))
        return

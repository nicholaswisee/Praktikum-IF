#include "server.h"

void solution() {
    FILE *request = fopen("request.txt", "r");
    FILE *response = fopen("response.txt", "w");


    char line[MAX_LINE];
    char method[MAX_LINE];
    char path[MAX_LINE];
    char contentType[MAX_LINE] = "n/a";
    char body[MAX_BODY];
    char http[MAX_LINE];
    int contentLength = 0;
    int headerFinished = 1;

    //baris pertama
    if (fgets(line, MAX_LINE, request) != NULL) {
        sscanf(line, "%s %s %s", method, path, http);
    }

    while (fgets(line, MAX_LINE, request)) {
        //check for end of header
        if (strcmp(line, "\r\n") == 0 || strcmp(line, "\n") == 0) {
            headerFinished = 1;
        }

        //retrieve content-type
        if (strstr(line, "Content-Type:" )) {
            sscanf(line, "Content-Type: %s", contentType);
        }

        //retrieve content-length
        if (strstr(line, "Content-Length:" )) {
            sscanf(line, "Content-Length: %d", &contentLength);
        }

    }


    
    //output
    fprintf(response, "HTTP/1.1 200 OK\n");
    fprintf(response, "Content-Type: text/plain\n");
    fprintf(response, "\n");
    fprintf(response, "Method: %s\n", method);
    fprintf(response, "Path: %s\n", path);
    fprintf(response, "Content-Type: %s\n", contentType);
    fprintf(response, "Body: %s\n", body);
    
    
    fclose(request);
    fclose(response);
}

int main(){

    solution();

    return 0;
}
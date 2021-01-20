
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define NAME_SIZE 16
void error_handling(char *message);
void read_message(int sock, char *buf);
void write_message(int sock, char *buf);
char name[NAME_SIZE] = "[NULL]";
int main(int argc, char *argv[])
{
    int sock;
    pid_t pid;
    char message[BUF_SIZE];
    struct sockaddr_in serv_adr;
    

    //프로그램 실행시 IP, PORT번호, 이름을 입력받음
    if (argc != 4)
    {
        printf("Usage : %s [IP] [PORT] [사용자 이름]\n", argv[0]);
        exit(1);
    }
    //유저 이름 저장
    sprintf(name, "[%s]", argv[3]);
    //클라이언트 소켓 설정
    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));
    
    if (connect(sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("connect() error!");

    //fork 함수로 입출력 제어
    pid = fork();
    if (pid == 0)
        write_message(sock, message);
    else
        read_message(sock, message);
    close(sock);
    return 0;
}
//메세지 READ 함수
void read_message(int sock, char *buf)
{
    char msg[NAME_SIZE + BUF_SIZE];
    while (1)
    {
        //서버에서 메시지를 읽어옴
        int str_len = read(sock, msg, NAME_SIZE + BUF_SIZE);
        //없으면 종료
        if (str_len == 0)
            return;
        //데이터 출력
        msg[str_len] = 0;
        fputs(msg, stdout);
    }
}

//메세지 WRITE 함수
void write_message(int sock, char *buf)
{
    char msg[NAME_SIZE + BUF_SIZE];
    while (1)
    {
        //입력값을 읽어옴
        fgets(buf, BUF_SIZE, stdin);
        //종료 구현
        if (!strcmp(buf, "q\n") || !strcmp(buf, "Q\n"))
        {
            shutdown(sock, SHUT_WR);
            return;
        }

        //데이터를 형식에 맞추어 쓰드록 지정
        sprintf(msg, "%s %s", name, buf);
        //입력한 메시지를 서버로 전송
        write(sock, msg, strlen(msg));
    }
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
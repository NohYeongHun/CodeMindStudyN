
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
 
#define BUF_SIZE 100
void error_handling(char *buf);
 
int main(int argc, char *argv[])
{
    //소켓, timeout값, fd_set값 등을 저장할 변수 선언
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    struct timeval timeout;
    fd_set reads, cpy_reads;
    socklen_t adr_sz;
    int fd_max, str_len, fd_num, i;
    char buf[BUF_SIZE];
 
    //포트번호를 입력하지 않으면 오류 출력 후 종료
    if(argc!=2) {
        printf("Usage : %s [PORT]\n", argv[0]);
        exit(1);
    }
 
    //서버생성 단
    serv_sock=socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family=AF_INET;
    serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_adr.sin_port=htons(atoi(argv[1]));
    if(bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr))==-1)
        error_handling("bind() error");
    //서버 접속 수를 5로 지정
    if(listen(serv_sock, 5)==-1)
        error_handling("listen() error");
 
    //fd_set형 변수 reads의 모든 비트를 0으로 초기화
    FD_ZERO(&reads);
    //소켓 디스크립터 정보를 등록
    FD_SET(serv_sock, &reads);
    //소켓의 번호를 저장
    fd_max=serv_sock;
 
    while(1) {
        //변수 복사
        cpy_reads=reads;
        //타임아웃 시간 설정
        timeout.tv_sec=5;
        timeout.tv_usec=5000;
        //모든 파일디스크립터를 대상으로 수신된 데이터가 있는지 검사
        if((fd_num=select(fd_max+1, &cpy_reads, 0, 0, &timeout))==-1) {
            break;
        }
        //Timeout이 발생하면 continue 수행
        if(fd_num==0) {
            continue;
        }
        //변화가 발생했다면
        for(i=0; i<fd_max+1; i++) {
            if(FD_ISSET(i, &cpy_reads)) {
                // 연결요청이 발생하면
                if(i==serv_sock) {
                    //연결요청 수락    
                    adr_sz=sizeof(clnt_adr);
                    clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
                    //해당 연결을 감시하도록 FD_SET을 통해 설정
                    FD_SET(clnt_sock, &reads);
                    //연결을 통해 clnt_sock 값이 증가했다면 fd_max 재설정
                    //(연결종료 된 클라이언트 < 새로 연결된 클라이언트)이라면 
                    if(fd_max<clnt_sock)
                        fd_max=clnt_sock;
                    printf("접속한 클라이언트 : %d \n", clnt_sock);
                }
                else {
                    str_len=read(i, buf, BUF_SIZE);
                    //종료 요청이 왔다면 연결 종료, fd_set값 초기화, 해당 소켓 종료
                    if(str_len==0) {    
                        FD_CLR(i, &reads);
                        close(i);
                        printf("종료한 클라이언트: %d \n", i);
                    }
                    else {
                        //메세지를 접속한 클라이언트 모두에게 보냄
                        for(int j=4; j < fd_max + 1; j++) { 
                            write(j, buf, str_len);
                        }
                        buf[str_len] = 0;
                        printf("%s", buf);
                    }
                }
            }
        }
    }
    
    close(serv_sock);
    return 0;
}
 
void error_handling(char *buf) {
    fputs(buf, stderr);
    fputc('\n', stderr);
    exit(1);
}

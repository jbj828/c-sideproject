#include <arpa/inet.h>  // htnol, htons, INADDR_ANY, sockaddr_in
#include <stdio.h>
#include <stdlib.h>  // atoi
#include <string.h>  // memset
#include <sys/socket.h>
#include <unistd.h>  // sockaddr_in, read, write

void error_handling(char* message);

int main(int arg, char* argv[]) {
  int clnt_sock;
  struct sockaddr_in serv_addr;
  char message[1024] = {
      0x00,
  };

  // TCP연결지향형이고 ipv4 도메인을 위한 소켓을 생성
  clnt_sock = socket(PF_INET, SOCK_STREAM, 0);
  if (clnt_sock == -1) error_handling("socket error");

  // 인자로 받은 서버 주소 정보를 저장
  memset(&serv_addr, 0, sizeof(serv_addr));
  // 서버 주소체계는 ipv4
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_addr.sin_port = htons(atoi(argv[2]));

  // 클라이언트 소켓 부분에 서버를 연결
  if (connect(clnt_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) ==
      -1) {
    error_handling("connect error");
  }

  // 연결이 성공 -> 데이터 받기
  if (read(clnt_sock, message, sizeof(message) - 1) == -1) {
    error_handling("read error");
  }
  printf("Message from server: %s\n", message);

  close(clnt_sock);

  return 0;
}

void error_handling(char* message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}
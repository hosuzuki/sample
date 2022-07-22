#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ  (0)
#define WRITE (1)

/**
 *  * @param *fd_r 読み込み用ファイルディスクリプタ
 *   * @param *fd_w 書き込み用ファイルディスクリプタ
 *    */
int popen2(int *fd_r, int *fd_w) {

//	子から親への通信用パイプ
		int pipe_child2parent[2];

//	親から子への通信用パイプ
		int pipe_parent2child[2];

//	プロセスID
		int pid;

//	パイプを生成
		if (pipe(pipe_child2parent) < 0) {
//			パイプ生成失敗
				perror("popen2");
			return 1;
		}

//	パイプを生成
		if (pipe(pipe_parent2child) < 0) {
//			パイプ生成失敗
			perror("popen2");

//			上で開いたパイプを閉じてから終了
			close(pipe_child2parent[READ]);
			close(pipe_child2parent[WRITE]);
			return 1;
		}

//	fork
		if ((pid = fork()) < 0) {
//			fork失敗
				perror("popen2");

//			開いたパイプを閉じる
				close(pipe_child2parent[READ]);
			close(pipe_child2parent[WRITE]);

			close(pipe_parent2child[READ]);
			close(pipe_parent2child[WRITE]);

			return 1;
		}

//	子プロセスか？
		if (pid == 0) {
			printf("child\n");
			//			子プロセスの場合は、親→子への書き込みはありえないのでcloseする
				close(pipe_parent2child[WRITE]);

//			子プロセスの場合は、子→親の読み込みはありえないのでcloseする
				close(pipe_child2parent[READ]);

//			親→子への出力を標準入力として割り当て
				dup2(pipe_parent2child[READ], 0);

//			子→親への入力を標準出力に割り当て
				dup2(pipe_child2parent[WRITE], 1);

//			割り当てたファイルディスクリプタは閉じる
				close(pipe_parent2child[READ]);
			close(pipe_child2parent[WRITE]);

//			子プロセスはここで該当プログラムを起動しリターンしない
//			printf("child2\n");
			if (execl("./test1", "./test1", NULL) < 0) {
					perror("popen2");
					close(pipe_parent2child[READ]);
					close(pipe_child2parent[WRITE]);
//			printf("child2\n");
//			write(1, "child3", 6);
			return 1;
				}
		}

//	親プロセス側の処理
	printf("p_child2paretn[write]:%d\n", pipe_child2parent[WRITE]);
	printf("p_parent2child[read]:%d\n", pipe_parent2child[READ]);
	close(pipe_parent2child[READ]);
	close(pipe_child2parent[WRITE]);
	printf("parent1\n");
	printf("p_child2paretn[read]:%d\n", pipe_child2parent[READ]);
	printf("p_parent2child[wirte]:%d\n", pipe_parent2child[WRITE]);
	*fd_r = pipe_child2parent[READ];
	*fd_w = pipe_parent2child[WRITE];

	return pid;
}

int main(int argc, char *argv[]) {
	int fd_r = fileno(stdin);
	int fd_w = fileno(stdout);

	if (argc < 2) {
		printf("Usage: %s <message>\n", argv[0]);
		return 1;
	}

	popen2(&fd_r, &fd_w);
	printf("1\n");

	write(fd_w, argv[1], strlen(argv[1]));
	printf("2\n");

	char buf[255];
	int size = read(fd_r, buf, 255);
	
	printf("3\n");
	if (size == -1) {
		perror("error");
		return 1;
	}
	printf("test2:");
	fwrite(buf, 1, size, stdout);
	printf("\n");

	return 0;
}

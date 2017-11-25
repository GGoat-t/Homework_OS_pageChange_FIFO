#include "queue.h"
#include <stdbool.h>
#pragma warning(disable: 4996)

//해당 프레임에 필요한 페이지 번호가 존재하는지 찾아봄, 있으면 1 없으면 0
bool isThere(int* frame, int pageNum) {
	for (int i = 0; i < MAX; i++) {
		if (*(frame + i) == pageNum) {
			return true;
		}
	}
	return false;
}

int main(int argc, const char** argv[]) {
	int pageList[20] = { 7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1 };

	int pageListLength = (int)(sizeof(pageList) / sizeof(int));
	//페이지 부재 수 카운트하는 변수
	int noPage = 0;
	queue_init();

	for (int i = 0; i < pageListLength; i++) {
		if (!(isThere(queue, pageList[i]))) {
			++noPage;
			//큐가 꽉 차있지 않고 필요한 페이지가 프레임에 존재하지 않으면, 큐에 현재 필요한 페이지 번호 삽입
			if (!(queue_isFull())){
				queue_put(pageList[i]);
			}
			//큐가 꽉 차있고 필요한 페이지가 프레임에 존재하지 않으면 queue_get을 하고 queue_put을 필요한 프레임 번호를 삽입한다.
			else
			{
				queue_get();
				queue_put(pageList[i]);
			}
		}
		//큐가 꽉 차있지 않고 필요한 페이지가 프레임에 존재하면 통과
		else {
			//nothing happens.
		}
		queue_print();
	}
	
	printf("페이지 부재 횟수는 %d입니다.\n", noPage);
	//printf("%d", isThere(frame, pageList[0]));
	return 0;
}

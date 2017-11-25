#include "queue.h"
#include <stdbool.h>
#pragma warning(disable: 4996)

//�ش� �����ӿ� �ʿ��� ������ ��ȣ�� �����ϴ��� ã�ƺ�, ������ 1 ������ 0
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
	//������ ���� �� ī��Ʈ�ϴ� ����
	int noPage = 0;
	queue_init();

	for (int i = 0; i < pageListLength; i++) {
		if (!(isThere(queue, pageList[i]))) {
			++noPage;
			//ť�� �� ������ �ʰ� �ʿ��� �������� �����ӿ� �������� ������, ť�� ���� �ʿ��� ������ ��ȣ ����
			if (!(queue_isFull())){
				queue_put(pageList[i]);
			}
			//ť�� �� ���ְ� �ʿ��� �������� �����ӿ� �������� ������ queue_get�� �ϰ� queue_put�� �ʿ��� ������ ��ȣ�� �����Ѵ�.
			else
			{
				queue_get();
				queue_put(pageList[i]);
			}
		}
		//ť�� �� ������ �ʰ� �ʿ��� �������� �����ӿ� �����ϸ� ���
		else {
			//nothing happens.
		}
		queue_print();
	}
	
	printf("������ ���� Ƚ���� %d�Դϴ�.\n", noPage);
	//printf("%d", isThere(frame, pageList[0]));
	return 0;
}

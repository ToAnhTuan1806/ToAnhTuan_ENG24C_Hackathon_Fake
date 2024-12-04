#include<stdio.h>

int main(){
	int arr[100];
	int i, j, choice, n=0;
	int max, pos, value, temp;
	int searchValue, check;
	do {
		printf("\nMENU\n");
		printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
		printf("2. In ra cac phan tu dang quan ly\n");
		printf("3. In ra gia tri lon nhat cua mang\n");
		printf("4. In ra cac phan la so nguyen to trong mang\n");
		printf("5. Them mot phan tu vao mang\n");
		printf("6. Xoa mot phan tu trong mang\n");
		printf("7. Sap xep mang theo thu tu tang dan\n");
		printf("8. Tim kiem phan tu (nguoi dung nhap) va in ra vi tri index cua phan tu do\n");
		printf("9. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		
		switch(choice) {
			//case 1: Nhap so phan tu can nhap va gia tri cac phan tu
			case 1: {
				printf("Nhap so phan tu can nhap: ");
				scanf("%d", &n);
				for(i=0; i<n; i++) {
					printf("arr[%d] = ", i);
					scanf("%d", &arr[i]);
				}
				break;
			}
			//case 2: In ra cac phan tu dang quan ly
			case 2: {
				printf("Cac phan tu mang dang quan ly: ");
				for(i=0; i<n; i++) {
					printf("%d ", arr[i]);
				}
				printf("\n");
				break;
			}
			//case 3: In ra gia tri lon nhat cua mang
			case 3: {
				max = arr[0];
				for(i=1; i<n; i++) {
					if(arr[i]>max) {
						max = arr[i];
					}
				}
				printf("Gia tri lon nhat cua mang: %d\n", max);
				break;
			}
			//case 4: In ra cac phan la so nguyen to trong mang
			case 4: {
				printf("Cac phan tu la so nguyen to trong mang: ");
				for(i=0; i<n; i++) {
					if(arr[i]<10) {
						switch(arr[i]) {
							case 2:
							case 3:
							case 5:
							case 7:
								printf("%d ", arr[i]);
								break;
						}
					} else {
						int j, prime =1;
						if(arr[i]<=1) {
							prime =0;
						} else {
							for(j=2; j*j<=arr[i]; j++) {
								if(arr[i] % j ==0) {
									prime =0;
									break;
								}
							}
						}
						if(prime) {
							printf("%d ", arr[i]);
						}
					}
				}
				printf("\n");
				break;				
			}
			//case 5: Them mot phan tu vao mang
			case 5: {
				printf("Nhap vi tri muon them moi vao mang: ");
				scanf("%d", &pos);
				printf("Nhap gia tri muon them moi vao mang: ");
				scanf("%d", &value);
				
				if(pos<0 || pos>n) {
					printf("Vi tri khong hop le\n");
				} else {
					for(i=n; i>pos; i--){
						arr[i] = arr[i-1];
					}
					arr[pos] = value;
					n++;
				}
				for(i=0; i<n; i++) {
					printf("%d ", arr[i]);
				}
				printf("\n");
				break;
			}
			//case 6: Xoa mot phan tu trong mang
			case 6: {
				printf("Nhap vi tri muon xoa phan tu: ");
				scanf("%d", &pos);
				if(pos<0 || pos>n) {
					printf("So nhap vao khong hop le. Thu lai!");
				} else {
					for(i=pos; i<n-1; i++) {
						arr[i] = arr[i+1];
					}
					n--;
				}				
				printf("Mang sau khi xoa: ");
				for(i=0; i<n; i++){
					printf("%d ", arr[i]);
				}
				printf("\n");
				break;
			}
			//case 7: Sap xep mang theo thu tu tang dan
			case 7: {
				for(i=0; i<n-1; i++) {
					for(j=0; j<n-i-1; j++) {
						if(arr[j] > arr[j+1]) {
							temp = arr[j];
							arr[j] = arr[j+1];
							arr[j+1] = temp;
						}
					}
				}
				printf("Mang duoc sap xep theo thu tu tang dan:\n");
					for(i=0; i<n;i++){
						printf("%d ", arr[i]);
				}
				printf("\n");
				break;
				
			}
			//case 8: Tim kiem phan tu (nguoi dung nhap) va in ra vi tri index cua phan tu do
			case 8: {
			 	check=0;
			 	printf("Nhap gia tri can tim: ");
			 	scanf("%d", &searchValue);
			 	for(i=0; i<n; i++) {
			 		if(arr[i] == searchValue) {
			 			printf("Phan tu %d xuat hien tai vi tri arr[%d]\n", searchValue, i);
			 			check=1;
			 			break;			 			
					 }
				 }
				if(check == 0) {
					printf("Phan tu %d khong co trong mang\n", searchValue);
				}
				break;
			}
			//case 9: Thoat
			case 9: {
			 	printf("Thoat chuong trinh\n");
				break;
				
				default:
					printf("Lua chon khong hop le\n");
			 }	
		} 
	} while (choice != 9);

	return 0;
}


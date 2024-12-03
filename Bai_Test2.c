#include<stdio.h>


int main() {
    int arr[100][100];
    int rows, cols, choice;
    int i, j, temp;
    int searchValue, check;
    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu tren duong bien va tinh tich\n");
        printf("4. In ra cac phan tu tren duong cheo chinh\n");
        printf("5. In ra cac phan tu tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
        	// case 1: Nhap kich co va gia tri cac phan tu cua mang
            case 1: {
                printf("Nhap so hang: ");
                scanf("%d", &rows);
                printf("Nhap so cot: ");
                scanf("%d", &cols);
                printf("Nhap gia tri cho phan tu:\n");
                for(i=0; i<rows; i++) {
                    for(j=0; j<cols; j++) {
                        printf("arr[%d][%d]: ", i, j);
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;
            }
            // case 2: In gia tri cac phan tu cua mang theo ma tran
            case 2: {
                printf("Gia tri cac phan tu cua mang theo ma tran:\n");
                for(i=0; i<rows; i++) {
                    for(j=0; j<cols; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            //case 3: In ra cac phan tu tren duong bien va tinh tich
            case 3: {
            	int product = 1;
                printf("Phan tu nam tren duong bien cua mang: ");
                for(i=0; i<rows; i++) {
                    for(j=0; j<cols; j++) {
                        if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                            product *= arr[i][j];
                            printf("%d ", arr[i][j]);
                        }
                    }
                }
                printf("\nTich cac phan tu tren duong bien la: %d\n", product);
                break;
            }
			
			//case 4: In ra cac phan tu tren duong cheo chinh
			case 4: {
				printf("Phan tu tren duong cheo chinh: ");
                for(i=0; i<rows; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;
            }
			//case 5: In ra cac phan tu tren duong cheo phu
			case 5: {
				printf("Phan tu tren duong cheo phu: ");
				for(i=0; i<rows; i++) {
					printf("%d ", arr[i][cols - i - 1]);
				}
				printf("\n");
				break;
			}
			//case 6: Sap xep duong cheo chinh theo thu tu tang dan
			
			case 6: {
				if(rows!=cols) {
					printf("Khong phai ma tran vuong khong the sap xep duong cheo chinh\n");
					break;
				}
				for(i=0; i<rows-1; i++) {
					for(j=i+1; j<rows; j++) {
						if(arr[i][i]>arr[j][j]) {
							temp = arr[i][i];
							arr[i][i] = arr[j][j];
							arr[j][j] = temp;
						}
					}
				}
				printf("Da sap xep duong cheo chinh tang dan:\n");	
				for(i=0; i<rows; i++) {
					printf("%d ", arr[i][i]);
				}
				printf("\n");
				break;
			}
			// case 7: Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang
			case 7: {
				check = 0;
				printf("Nhap gia tri can tim: ");
				scanf("%d", &searchValue);
				for(i=0; i<rows; i++) {
					for(j=0; j<cols; j++) {
						if(arr[i][j] == searchValue) {
							printf("Phan tu %d xuat hien tai vi tri arr[%d][%d]\n", searchValue, i, j);
							check = 1;
						}
					}
				}
				if(check == 0) {
					printf("Phan tu %d khong co trong mang\n", searchValue);
				}
				break;
			}
			// case 8: Thoat
			case 8: {
				printf("Thoat chuong trinh\n");
				break;
			}
			default: {
				printf("Lua chon khong hop le, thu lai!\n");
				break;
			}
	} 

	} while(choice != 8);		
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char Hoten[25];
    char Masv[10];
    float toan;
    float van;
    float anh;


} Thongtin;

void chuanhoa(char *Hoten) {
    *Hoten = toupper(*Hoten);
    for (int i = 1; i < strlen(Hoten); i++) {
        if (Hoten[i] == ' ') {
            Hoten[i + 1] = toupper(Hoten[i + 1]);
        }
    }
    while (Hoten[0] == ' ') {
        strcpy(&Hoten[0], &Hoten[1]);
    }
    for (int i = 0; i < strlen(Hoten); i++) {
        if (Hoten[i] == ' ' && Hoten[i + 1] == ' ') {
            strcpy(&Hoten[i], &Hoten[i + 1]);
            i--;
        }
    }
    while (Hoten[strlen(Hoten) - 1] == ' ') {
        strcpy(&Hoten[strlen(Hoten) - 1], &Hoten[strlen(Hoten)]);
    }
}

Thongtin Sinhvien[100];
int demsv = 0;

void Nhapthongtin() {
    Thongtin Add;

    printf("Nhap ho ten sinh vien: ");
    scanf("%[^\n]", &Add.Hoten);

    chuanhoa(Add.Hoten);

    printf("Nhap ma sinh vien: ");
    scanf("%s", &Add.Masv);
    getchar();

    printf("Nhap diem toan sinh vien: ");
    scanf("%f", &Add.toan);
    getchar();

    printf("Nhap diem van sinh vien: ");
    scanf("%f", &Add.van);
    getchar();

    printf("Nhap diem anh sinh vien: ");
    scanf("%f", &Add.anh);
    getchar();

    Sinhvien[demsv++] = Add;
}

void HienThi() {
    for (int i = 0; i < 72; i++) {
        printf("_");
    }
    printf("\n");
    printf("|%3s|%-10s|%-25s|%-9s|%-9s|%-9s|\n", "STT","Ma Sv","Ho va Ten", "Diem Toan", "Diem Van", "Diem Anh");
    printf("|___|__________|_________________________|_________|_________|_________|\n");

    for (int i = 0; i < demsv; i++) {
        printf("|%3d|%-10s|%-25s|%-9.1f|%-9.1f|%-9.1f|\n", i + 1,Sinhvien[i].Masv,Sinhvien[i].Hoten, Sinhvien[i].toan, Sinhvien[i].van, Sinhvien[i].anh);
    }
    printf("|___|__________|_________________________|_________|_________|_________|\n");

}

	
//Hien thi
void Hienthi_1(Thongtin Sinhvien) {
    printf("Ho va ten: %s\n", Sinhvien.Hoten);
    printf("Ma Sinh Vien: %s\n", Sinhvien.Masv);
    printf("Diem Toan: %.2f\n", Sinhvien.toan);
    printf("Diem Van: %.2f\n", Sinhvien.van);
    printf("Diem Anh: %.2f\n", Sinhvien.anh);
    
}





//tim kiem
void timkiem() {
    char timsv[20];
    printf("Nhap ma sinh vien can tim : ");
    scanf("%s", timsv);
    printf("Sinh vien can tim : \n");
    int tim = 0;
    printf("______________________\n");
    for (int i = 0; i < demsv; i++) {
        if (strcmp(Sinhvien[i].Masv, timsv) == 0) {
            Hienthi_1(Sinhvien[i]);
            tim = 1;
            break;
        }
    }
    if (!tim) {
        printf("Khong tim thay sinh vien\n");
    }
    printf("______________________\n");
}


float trungbinh(Thongtin Sinhvien){

	float tb = (Sinhvien.anh + Sinhvien.toan + Sinhvien.van) /3;

	return tb;		
}
float tinh_all() {
    if (demsv == 0) {
        printf("Khong co sinh vien nao trong danh sach.\n");
        return 0;
    }

    float tongDiem = 0;
    for (int i = 0; i < demsv; i++) {
        tongDiem += trungbinh(Sinhvien[i]);
    }
    return tongDiem / demsv;
}
void hienthitb(){
	for (int i = 0; i < 58; i++) {
    printf("_");
    }
    printf("\n");
    printf("|%3s|%-10s|%-25s|%-15s|\n", "STT","Ma Sv","Ho va Ten", "Diem trung binh");
    printf("|___|__________|_________________________|_______________|\n");

    for (int i = 0; i < demsv; i++) {
        printf("|%3d|%-10s|%-25s|%-15.1f|\n", i + 1,Sinhvien[i].Masv,Sinhvien[i].Hoten, trungbinh(Sinhvien[i]));
    }
    printf("|___|__________|_________________________|_______________|\n");
	printf("|%3s|%10s|%25s|%-15.2f|\n","TB","          ","                         ",tinh_all());
	printf("|___|__________|_________________________|_______________|\n");
}


void xoasinhvien(){

    char xoa[20];
    printf("Nhap ma sinh vien can xoa : ");
    scanf("%s", xoa); 
    int tim = 0;

    for (int i = 0; i < demsv; i++) {
        if (strcmp(Sinhvien[i].Masv, xoa) == 0) {
            for(int j = i;j < demsv ; j++){
            	Sinhvien[j] = Sinhvien[j + 1];
			}
            demsv--;
            printf("Da xoa thanh cong!!!");
            tim = 1;
            break;
        }
    }
    if (!tim) {
        printf("Khong tim thay sinh vien\n");
    }

}

void suathongtin() {
    Thongtin suadoi;
    char sua[20];
    printf("Nhap ma sinh vien can sua : ");
    scanf("%s", sua);
    int tim = 0;

    for (int i = 0; i < demsv; i++) {
        if (strcmp(Sinhvien[i].Masv, sua) == 0) {
            printf("Nhap ho ten sinh vien: ");
            getchar();
            scanf("%[^\n]", &suadoi.Hoten);

            chuanhoa(suadoi.Hoten);

            printf("Nhap ma sinh vien: ");
            scanf("%s", &suadoi.Masv);
            getchar();

            printf("Nhap diem toan sinh vien: ");
            scanf("%f", &suadoi.toan);
            getchar();

            printf("Nhap diem van sinh vien: ");
            scanf("%f", &suadoi.van);
            getchar();

            printf("Nhap diem anh sinh vien: ");
            scanf("%f", &suadoi.anh);
            getchar();
            Sinhvien[i] = suadoi;

            tim = 1;
            printf("Da sua thong tin sinh vien.\n");
            break;
        }
    }
    if (!tim) {
        printf("Khong tim thay sinh vien can sua.\n");
    }
}






void LuuVaoFile(const char *tenFile) {
    FILE *file = fopen(tenFile, "w"); 

    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }

    
    for (int i = 0; i < demsv; i++) {
        fprintf(file, "%s|%s|%.1f|%.1f|%.1f\n", Sinhvien[i].Masv, Sinhvien[i].Hoten, Sinhvien[i].toan, Sinhvien[i].van, Sinhvien[i].anh);
    }

    fclose(file); 
    printf("Da luu du lieu vao file.\n");
}

int main() {
    int choice;
    
    while(1) {
        printf("\nMENU:\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Tim kiem sinh vien\n");
        printf("4. Thong ke diem trung binh\n");
        printf("5. Xoa sinh vien\n");
        printf("6. Sua thong tin\n");
        printf("7. Luu vao file\n");
        printf("0. Thoat chuong trinh\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                Nhapthongtin();
                break;
            case 2:
                HienThi();
                break;
            case 3:
                timkiem();
                break;
            case 4:
                hienthitb();
                break;
            case 5:
                xoasinhvien();
                break;
            case 6:
                suathongtin();
                break;
            case 7:
            	LuuVaoFile("C:/Users/Admin/Downloads/sinhvien.txt");
            	break;
            case 0:
                printf("Chuong trinh ket thuc. Tam biet!\n");
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }

    return 0;
}


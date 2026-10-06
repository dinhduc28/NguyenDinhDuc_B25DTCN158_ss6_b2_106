#include <stdio.h>
#include <string.h>

int main() {
    const int MAX = 100;

    char maPhieu[100][15];
    char tenSach[100][50];
    int soNgayMuon[100];
    int tienPhat[100];
    int soLuong = 0;

    int luaChon;
    int i, j, index;
    int ngayMoi;
    int tongTienPhat;
    char maNhap[15];

    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat\n");
        printf("6. Thoat chuong trinh\n");
        printf("==============================================================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        while (getchar() != '\n');

        switch (luaChon) {
            case 1:
                if (soLuong >= MAX) {
                    printf("He thong day, khong the them phieu muon moi!\n");
                    break;
                }

                printf("\n=== THEM LUOT MUON SACH MOI ===\n");

                do {
                    printf("Nhap ma phieu muon: ");
                    scanf("%14s", maPhieu[soLuong]);
                    while (getchar() != '\n');

                    index = -1;

                    for (i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[soLuong], maPhieu[i]) == 0) {
                            index = i;
                            break;
                        }
                    }

                    if (index != -1) {
                        printf("Ma phieu da ton tai! Vui long nhap lai.\n");
                    }

                } while (index != -1);

                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], sizeof(tenSach[soLuong]), stdin);

                if (tenSach[soLuong][strlen(tenSach[soLuong]) - 1] == '\n') {
                    tenSach[soLuong][strlen(tenSach[soLuong]) - 1] = '\0';
                }

                do {
                    printf("Nhap so ngay muon thuc te: ");
                    scanf("%d", &soNgayMuon[soLuong]);
                    while (getchar() != '\n');

                    if (soNgayMuon[soLuong] <= 0) {
                        printf("So ngay muon phai lon hon 0! Vui long nhap lai.\n");
                    }

                } while (soNgayMuon[soLuong] <= 0);

                tienPhat[soLuong] = (soNgayMuon[soLuong] > 14)
                    ? (soNgayMuon[soLuong] - 14) * 5000
                    : 0;

                printf("--> Tien phat tu dong tinh: %d VNÐ\n", tienPhat[soLuong]);

                soLuong++;

                printf("--> Them luot muon sach thanh cong!\n");
                break;

            case 2:
                if (soLuong == 0) {
                    printf("Danh sach muon sach hien dang rong!\n");
                    break;
                }

                printf("\n================================ DANH SACH MUON SACH ================================\n");
                printf("%-5s | %-10s | %-30s | %-10s | %-15s\n",
                       "STT", "Ma Phieu", "Ten Sach", "So Ngay", "Tien Phat");
                printf("-------------------------------------------------------------------------------------\n");

                tongTienPhat = 0;

                for (i = 0; i < soLuong; i++) {
                    printf("%-5d | %-10s | %-30s | %-10d | %-15d\n",
                           i + 1,
                           maPhieu[i],
                           tenSach[i],
                           soNgayMuon[i],
                           tienPhat[i]);

                    tongTienPhat += tienPhat[i];
                }

                printf("-------------------------------------------------------------------------------------\n");
                printf("Tong tien phat toan he thong: %d VNÐ\n", tongTienPhat);
                break;

            case 3:
                printf("\n=== CAP NHAT SO NGAY MUON ===\n");
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%14s", maNhap);
                while (getchar() != '\n');

                index = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(maNhap, maPhieu[i]) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maNhap);
                } else {
                    printf("Tim thay phieu muon cua sach: %s (So ngay hien tai: %d)\n",
                           tenSach[index], soNgayMuon[index]);

                    do {
                        printf("Nhap so ngay muon thuc te moi: ");
                        scanf("%d", &ngayMoi);
                        while (getchar() != '\n');

                        if (ngayMoi <= 0) {
                            printf("So ngay muon phai lon hon 0! Vui long nhap lai.\n");
                        }

                    } while (ngayMoi <= 0);

                    soNgayMuon[index] = ngayMoi;

                    tienPhat[index] = (soNgayMuon[index] > 14)
                        ? (soNgayMuon[index] - 14) * 5000
                        : 0;

                    printf("--> Tien phat moi: %d VNÐ\n", tienPhat[index]);
                    printf("--> Cap nhat so ngay muon thanh cong!\n");
                }
                break;

            case 4:
                printf("\n=== XOA LUOT MUON SACH ===\n");
                printf("Nhap ma phieu muon can xoa: ");
                scanf("%14s", maNhap);
                while (getchar() != '\n');

                index = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(maNhap, maPhieu[i]) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maNhap);
                } else {
                    for (i = index; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(tenSach[i], tenSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                        tienPhat[i] = tienPhat[i + 1];
                    }

                    soLuong--;

                    printf("Xoa phieu muon thanh cong!\n");
                }
                break;

            case 5:
                printf("\n=== THONG KE PHIEU MUON BI PHAT ===\n");

                index = 0;

                for (i = 0; i < soLuong; i++) {
                    if (soNgayMuon[i] > 14) {
                        printf("%-5d | %-10s | %-30s | %-10d | %-15d\n",
                               i + 1,
                               maPhieu[i],
                               tenSach[i],
                               soNgayMuon[i],
                               tienPhat[i]);

                        index++;
                    }
                }

                if (index == 0) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                }
                break;

            case 6:
                printf("Cam on ban da su dung he thong!\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }

    } while (luaChon != 6);

    return 0;
}

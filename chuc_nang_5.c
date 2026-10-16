#include <stdio.h>
#include "rapphim.h"

// ==========================================
// HÀM 1: LƯU SƠ ĐỒ XUỐNG FILE (Ghi nhớ)
// ==========================================
void LuuFileSoDo(int so_do[8][10]) {
    // Mở file ở chế độ "w" (Write - Viết/Ghi đè)
    FILE *file = fopen("DuLieuRapPhim.txt", "w");

    if (file == NULL) {
        printf("Loi: Khong the tao file de luu du lieu!\n");
        return;
    }

    // Dùng 2 vòng lặp quét mảng, in các số 0 và 1 vào file
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++) {
            // fprintf hoạt động y hệt printf, nhưng nó in vào file thay vì in ra màn hình
            fprintf(file, "%d ", so_do[i][j]);
        }
        fprintf(file, "\n"); // Hết 10 cột thì xuống dòng trong file cho đẹp
    }

    fclose(file); // Nhớ đóng file lại sau khi ghi xong!
}

// ==========================================
// HÀM 2: ĐỌC SƠ ĐỒ TỪ FILE (Phục hồi trí nhớ)
// ==========================================
void DocFileSoDo(int so_do[8][10]) {
    // Mở file ở chế độ "r" (Read - Đọc)
    FILE *file = fopen("DuLieuRapPhim.txt", "r");

    // Nếu file chưa tồn tại (chạy chương trình lần đầu tiên)
    if(file == NULL) {
        // Tự động khởi tạo rạp trống (gán toàn bộ bằng 0)
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 10; j++) {
                so_do[i][j] = 0;
            }
        }
        return; // Thoát hàm
    }

    // Nếu file đã có, dùng fscanf để "hút" từng con số trong file đắp ngược lại vào mảng
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 10; j++) {
            fscanf(file, "%d", &so_do[i][j]);
        }
    }

    fclose(file);
}

// ==========================================
// HÀM 3: THỐNG KÊ DOANH THU & LẤP ĐẦY
// ==========================================
void ThongKeRapPhim(int so_do[8][10]) {
    int ghe_da_dat = 0;
    float doanh_thu = 0;

    printf("\n--- BAO CAO THONG KE RAP PHIM ---\n");

    // Quét toàn bộ rạp xem ghế nào là số 1 (Đã đặt)
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 10; j++) {
            if(so_do[i][j] == 1) {
                ghe_da_dat++; // Tăng biến đếm số ghế lên 1

                // Tính tiền: Nếu rơi vào hàng G (i=6) hoặc H (i=7) thì cộng 100k, còn lại 70k
                if(i == 6 || i == 7) {
                    doanh_thu += 100000.0;
                }
                else {
                    doanh_thu += 70000.0;
                }
            }
        }
    }

    // Ép kiểu (float) để phép chia có phần thập phân. Tổng rạp có 80 ghế (8x10).
    float ti_le = ((float)ghe_da_dat / 80.0) * 100.0;

    printf("- So ghe da ban  : %d / 80 ghe\n", ghe_da_dat);
    printf("- Ti le lap day  : %.1f %%\n", ti_le);
    printf("- TONG DOANH THU : %.0f VND\n", doanh_thu);
}

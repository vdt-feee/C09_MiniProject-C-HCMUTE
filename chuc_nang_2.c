#include <stdio.h>
#include <stdlib.h>  // Dùng cho hàm atoi (chuyển chuỗi thành số)
#include <ctype.h>   // Dùng cho hàm toupper (chuyển chữ thường thành hoa)
#include "rapphim.h"

float datVe(int so_do[8][10]) {
    int so_luong;
    float tong_tien = 0;
    int kiem_tra;

    printf("\n--- DAT VE XEM PHIM ---\n");

    // hỏi ng dùng muốn đặt bao nhiêu ghế và Bắt lỗi nhập dữ liệu sai
    do{
        printf("Ban muon dat bao nhieu ghe? (Toi da 80): ");
        kiem_tra = scanf("%d", &so_luong);

        if(kiem_tra == 0) {
            printf("Loi: Ban da nhap chu. Vui long nhap so!\n");
            while(getchar() != '\n'); // Hút rác bàn phím
        } else if (so_luong <= 0 || so_luong > 80) {
            printf("Loi: So luong ghe khong hop le!\n");
        }
    }while(kiem_tra == 0 || so_luong <= 0 || so_luong > 80);

    // Vòng lặp cho phép chọn từng ghế
    for(int i = 0; i < so_luong; i++) {
        char toa_do[10];
        int r, c; // r: row (hàng), c: column (cột)
        int hop_le = 0; // Cờ đánh dấu kiểm tra trạng thái

        do {
            printf("Nhap toa do ghe thu %d (VD: A5, H10): ", i + 1);
            scanf("%s", toa_do);

            // --- THUẬT TOÁN DỊCH TỌA ĐỘ ---

            // Lấy ký tự đầu tiên, ép thành chữ HOA (lỡ người dùng gõ 'a5' thì biến thành 'A')
            char hang = toupper(toa_do[0]);

            // Bỏ qua ký tự đầu, lấy phần đuôi ép thành số nguyên (VD: "5" -> 5, "10" -> 10)
            int cot = atoi(&toa_do[1]);

            // Dịch chữ sang chỉ số mảng: 'A' - 'A' = 0; 'B' - 'A' = 1...
            r = hang - 'A';

            // Dịch cột sang chỉ số mảng: Cột 5 thì nằm ở vị trí số 4 trong mảng
            c = cot - 1;

            // --- BẮT LỖI TỌA ĐỘ ---

            // Lỗi 1: Nhập tào lao (VD: Z99, A15)
            if(r < 0 || r > 7 || c < 0 || c > 9) {
                printf("Loi: Toa do khong ton tai; Hang phai tu A-H, Cot phai tu 1-10.\n");
            }
            // Lỗi 2: Ghế đã có người đặt (so_do[r][c] == 1)
            else if (so_do[r][c] == 1) {
                printf("Loi: Ghe %s da co nguoi dat roi. Vui long chon ghe khac!\n", toa_do);
            }
            // Nếu vượt qua hết thì hợp lệ, thoát vòng lặp do-while
            else {
                hop_le = 1;
            }

        }while (hop_le == 0);

        // 3. Cập nhật mảng và Tính tiền ngay lập tức
        so_do[r][c] = 1; // Đánh dấu là đã đặt

        // Hàng G (r=6) và hàng H (r=7) là ghế VIP giá 100.000đ, còn lại 70.000 vnd
        float gia_ve = (r == 6 || r == 7) ? 100000.0 : 70000.0;
        tong_tien += gia_ve;

        printf("-> Dat thanh cong ghe %c%d (Gia: %.0f d)\n", hang, cot, gia_ve);
    }

    printf("------------------------------------------\n");
    printf("Tong tien cho %d ghe: %.0f d\n", so_luong, tong_tien);

    // Trả cục tiền này về cho Dev 4 in hóa đơn
    return tong_tien;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "rapphim.h"

void huyVe(int so_do[8][10]) {
    char toa_do[10];
    int r, c;
    int hop_le = 0;

    printf("\n--- HUY VE XEM PHIM ---\n");

    do{
        // Cho phép người dùng gõ '0' để thoát lỡ như họ bấm nhầm vào menu hủy vé
        printf("Nhap toa do ghe muon huy (VD: A5) hoac go '0' de thoat: ");
        scanf("%s", toa_do);

        // Xử lý nút thoát khẩn cấp
        if(toa_do[0] == '0') {
            printf("-> Da thoat chuc nang huy ve.\n");
            return; // Lệnh return sẽ kết thúc hàm ngay lập tức và quay về Menu chính
        }

        // --- TÁI SỬ DỤNG THUẬT TOÁN CHUYỂN ĐỔI TỌA ĐỘ CỦA CHỨC NĂNG 2 ---
        char hang = toupper(toa_do[0]);
        int cot = atoi(&toa_do[1]);

        r = hang - 'A';
        c = cot - 1;

        // --- LÀM NGƯỢC LẠI VỚI DEV 2 ---

        // Lỗi 1: Tọa độ nằm ngoài không gian rạp chiếu
        if(r < 0 || r > 7 || c < 0 || c > 9) {
            printf("Loi: Toa do khong ton tai! Hang phai tu A-H, Cot phai tu 1-10.\n");
        }
        // Lỗi 2: Ghế chưa có ai đặt (so_do[r][c] == 0) thì lấy gì mà hủy!
        else if(so_do[r][c] == 0) {
            printf("Loi: Ghe %s hien dang TRONG, ban khong the huy! Vui long nhap lai.\n", toa_do);
        }
        // Hợp lệ: Tọa độ đúng và ghế đang ở trạng thái đã đặt (1)
        else{
            hop_le = 1;
        }

    } while (hop_le == 0);

    // --- TIẾN HÀNH HỦY VÉ ---
    so_do[r][c] = 0; // Chuyển trạng thái ghế từ Đã đặt (1) về Trống (0)

    printf("-> Da huy thanh cong ghe %c%d. Ghe da duoc tra ve trang thai trong.\n", hang, cot);
}


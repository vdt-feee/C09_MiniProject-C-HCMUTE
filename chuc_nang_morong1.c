#include <stdio.h>
#include "rapphim.h"

void N_GheLienNhau(int so_do[8][10]) {
    int n;
    printf("\n--- GOI Y GHE LIEN NHAU ---\n");
    printf("Ban can tim bao nhieu ghe ngoi canh nhau? (1-10): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Loi: So luong ghe khong hop le!\n");
        return;
    }

    // Chỉ còn 2 vòng lặp duyệt hàng và cột
    for (int i = 0; i < 8; i++) {

        int dem_ghe_trong = 0; // Bộ đếm: Sang hàng mới thì phải reset về 0

        for (int j = 0; j < 10; j++) {

            if (so_do[i][j] == 0) {
                dem_ghe_trong++; // Thấy ghế trống -> Tăng bộ đếm
            } else {
                dem_ghe_trong = 0; // Đụng ghế có người -> Reset về 0 ngay lập tức
            }

            // Kiểm tra xem đã đếm đủ số ghế yêu cầu chưa
            if (dem_ghe_trong == n) {
                char hang = 'A' + i;

                // j đang đứng ở ghế cuối cùng của dãy.
                // Ghế bắt đầu = Ghế hiện tại (j) - số lượng (n) + 1.
                // Cộng thêm 1 nữa ở bên ngoài để đổi từ chỉ số mảng ra số thứ tự in cho khách xem.
                int ghe_bat_dau = (j - n + 1) + 1;
                int ghe_ket_thuc = j + 1;

                printf("-> Goi y day ghe dep: tu %c%d den %c%d.\n", hang, ghe_bat_dau, hang, ghe_ket_thuc);

                return; // Xong việc, thoát hàm luôn
            }
        }
    }

    printf("Hien tai rap khong con %d ghe xep lien nhau.\n", n);
}

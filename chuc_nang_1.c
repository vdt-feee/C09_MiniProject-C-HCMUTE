#include <stdio.h>
#include "rapphim.h" // Nhúng bản hợp đồng chung vào

void HienThiSoDo(int so_do[8][10]) {
    printf("\n===================================================\n");
    printf("                  MAN HINH CHIEU                   \n");
    printf("===================================================\n\n");

    // 1. In dải số thứ tự cột từ 1 đến 10 ở trên cùng
    printf("     "); // Thụt vào một chút để chừa chỗ cho cột tên hàng (A, B, C...)
    for(int j = 1; j <= 10;j++) {
        printf("%-4d", j); // %-4d giúp căn lề trái mỗi số chiếm đúng 4 khoảng trắng cho ngay ngắn
    }
    printf("\n");
    printf("   -----------------------------------------\n");

    // 2. Vòng lặp lồng nhau để quét mảng 2 chiều
    for(int i = 0; i < 8; i++) { // Vòng lặp duyệt 8 hàng

        // MẸO KỸ THUẬT: Chuyển số nguyên (0, 1, 2...) thành chữ cái (A, B, C...)
        // Trong bảng mã ASCII, chữ 'A' có giá trị là 65.
        // 65 + 0 = 65 ('A'), 65 + 1 = 66 ('B')...
        char ten_hang = 'A' + i;

        printf("%c  | ", ten_hang); // In tên hàng ở đầu mỗi dòng

        for(int j = 0; j < 10; j++) { // Vòng lặp duyệt 10 cột
            // Nếu giá trị trong mảng là 0 (Trống)
            if (so_do[i][j] == 0) {
                printf("[_] ");
            }
            // Nếu giá trị trong mảng là 1 (Đã đặt)
            else {
                printf("[X] ");
            }
        }

        // Trực quan hóa 2 hàng VIP (G và H, tương ứng với hàng số 6 và 7 trong mảng)
        if(i == 6 || i == 7) {
            printf(" (VIP)");
        }

        printf("\n"); // Hết 10 cột thì xuống dòng để in hàng tiếp theo
    }

    printf("\nGhi chu: [_] Ghe trong  |  [X] Ghe da dat\n");
    printf("         (Ghe VIP ap dung cho hang G va H)\n");
}

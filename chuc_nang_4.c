#include <stdio.h>
#include <time.h>
#include "rapphim.h"

void InHoaDon(float tong_tien) {
    // Nếu tổng tiền bằng 0 (người dùng chưa đặt ghế nào hoặc vừa hủy vé), thì không in hóa đơn.
    if (tong_tien <= 0) {
        return;
    }

    // Lấy thời gian thực của hệ thống để in lên vé
    time_t t = time(NULL);
    struct tm time_now = *localtime(&t);   // struct tm : kiểu dữ liệu; time_now là tên biến

    printf("\n");
    printf("************************************************\n");
    printf("*              RAP PHIM HCM-UTE              *\n");
    printf("*----------------------------------------------*\n");

    // In ngay gio in ve: Ngay/Thang/Nam Gio:Phut
    printf("* Ngay in ve: %02d/%02d/%d %02d:%02d                  *\n",
           time_now.tm_mday, time_now.tm_mon + 1, time_now.tm_year + 1900, time_now.tm_hour, time_now.tm_min);

    printf("*                                              *\n");

    // %15.0f để đẩy số tiền dịch sang phải, nhìn hóa đơn thẳng thớm hơn
    printf("* TONG TIEN CAN THANH TOAN: %15.0f VND *\n", tong_tien);
    printf("*                                              *\n");
    printf("*     Chuc quy khach xem phim vui ve!          *\n");
    printf("************************************************\n");
}

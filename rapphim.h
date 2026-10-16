// File: rapphim.h
#ifndef RAPPHIM_H
#define RAPPHIM_H

// 1. Chuc nang hien thi so do
void HienThiSoDo(int so_do[8][10]);

// 2. Chuc nang dat ve
float DatVe(int so_do[8][10]);

// 3. Chuc nang huy ve
void HuyVe(int so_do[8][10]);

// 4. Chuc nang in hoa don
void InHoaDon(float tong_tien);

// 5. Cac chuc nang thao tac File va Thong ke
void DocFileSoDo(int so_do[8][10]);
void LuuFileSoDo(int so_do[8][10]);
void ThongKeRapPhim(int so_do[8][10]);

// 6. Chuc nang mo rong: Goi y ghe
void N_GheLienNhau(int so_do[8][10]);

#endif

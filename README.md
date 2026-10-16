# MINI PROJECT: C09 - ĐẶT VÉ XEM PHIM

**Nhóm thực hiện:** Vũ Duy Thức, Trần Duy Nam, Cao Thanh Tuấn, Nguyễn Công Thuận, Nguyễn Ngọc Thịnh, Phan Quang Thành, Trần Ngọc Thắng, Trần Thành Long

### 1. Danh sách các file mã nguồn:
- `rapphim.h` (File thư viện chung)

- `main.c` (Menu chính điều hướng)
- `chuc_nang_1.c` đến `chuc_nang_5.c` (Các hàm xử lý chức năng bắt buộc)
- `chuc_nang_morong1.c` (Chức năng mở rộng: Gợi ý dãy ghế trống)


### 2. Hướng dẫn biên dịch và chạy (Nếu dùng Visual Studio Code):
- **Bước 1:** Mở Terminal tại thư mục chứa code.
- **Bước 2:** Gõ lệnh sau để biên dịch (gom các file lại):
  `gcc main.c chuc_nang_1.c chuc_nang_2.c chuc_nang_3.c chuc_nang_4.c chuc_nang_5.c chuc_nang_morong1.c -o rapphim`
- **Bước 3:** Gõ lệnh sau để chạy chương trình:
  `./rapphim` (trên hệ điều hành Mac/Linux) hoặc `.\rapphim.exe` (trên hệ điều hành Windows)



### 3. Hướng dẫn biên dịch và chạy (Nếu dùng Dev-C++ / Code::Blocks):
- **Bước 1:** Tạo một Project mới (File -> New -> Project -> Console Application).
- **Bước 2:** Kéo thả toàn bộ các file `.c` và `.h` vào chung Project này.
- **Bước 3:** Bấm phím F11 (Compile & Run) để chạy, nếu xài CodeBlocks thì nhấn F9.

Thư mục chứa cài đặt danh sách liên kết (DSLK), linked list, đơn giản.
Phiên bản 01:
- data là kiểu int, 
- phần data được để RIENG trong thư viện data_t.h.

Để chạy chương trình:
Bước 1: dịch các file .c ra file .o bằng lệnh sau:
  gcc -c llist.c 
  gcc -c llmain.c
Bước 2: liên kết các file .o lại để tạo ra file chạy test
  gcc -o test llist.o llmain.o
Dự án 1:

Thư viện các giải thuật sắp xếp trên kiểu dữ liệu nguyên:
0. data.c và data.h : định nghĩa kiểu data_t là kiểu số nguyên (int) và các thao tác cơ bản trên nó (swap, showData)
1. sort.c và sort.h : thư viện các thuật toán sắp xếp trên một mảng các phần tử có kiểu data_t
   Các giải thuật sắp xếp bao gồm: insertionSort, selectionSort, heapSort, quickSort, mergeSort
   !!! Dùng chung thư viện sort.c và sort.h như project char
2. main.c: chương trình minh họa cách sử dụng thư viện sort, với kiểu dữ liệu cơ bản dạng số nguyên (int)
3. main_makefile.mak: makefile hướng dẫn dịch


----------------------------------------------------------------
Dự án 2
0. data.c, data.h, sort.c, sort.h : tương tự dự án 1

1. mainTime.c: Đo thời gian chạy của 2 thuật toán sắp xếp khác nhau
2. main_makefile.mak: makefile hướng dẫn dịch
3. utils.c, utils.h: chứa hàm tiện ích để lấy thời gian tính bằng micro giây của hệ thống
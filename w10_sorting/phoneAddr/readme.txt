Thư viện các giải thuật sắp xếp:
0. data.c và data.h : định nghĩa kiểu data_t là kiểu CẤU TRÚC (phoneAddr) và các thao tác cơ bản trên nó:
	- swap, 
	- showData,
	- convert, 
	- so sánh bằng (eq), nhỏ hơn (lt), lớn hơn (gt)
	Chú ý: có sử dụng union để khái quát trường tìm kiếm dưới dạng thuộc tính 'key'
	
1. sort.c và sort.h : thư viện các thuật toán sắp xếp trên một mảng các phần tử có kiểu data_t
   Các giải thuật sắp xếp bao gồm: insertionSort, selectionSort, heapSort, quickSort, mergeSort
   Các giải thuật này có sử dụng các phép toán so sánh, đổi chỗ và copy dữ liệu kiểu data_t
   
2. main.c: chương trình minh họa cách sử dụng thư viện sort, với kiểu dữ liệu cơ bản dạng cấu trúc (phoneAddr), key để sắp xếp là email, thứ tự sắp xếp từ nhỏ đến lớn theo thứ tự chữ cái
3. makefile.mak: makefile hướng dẫn dịch

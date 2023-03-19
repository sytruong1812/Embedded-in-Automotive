# Embedded-in-Automotive

## I: Phân vùng nhớ (Memory Layout of C Program)
    1. Có 5 phân vùng nhớ trong RAM (Text, Data, BSS, Heap, Stack)
        1.1. Text Segment
        - Quyền truy cập là Read-only, chứa các lệnh để thực thi nên tránh sửa đổi 
          (Contains executable instructions)
        - Chứa khai báo hằng số trong chương trình (.rodata)
        - Sharable
        1.2. Data Segment
        - Quyền truy cập Read-Wire
        - Chứa các biến toàn cục (global variable) or biến static 
          với điều khiện là giá trị khởi tạo khác không.
        - Được giải phóng khi kết thúc chương trình.
        1.3. BSS (Uninitialized Data Segment)
        - Quyền truy cập Read-Write
        - Chứa các biến toàn cục (global variable) or biến static 
          với giá trị khởi tạo bằng không or không khởi tạo.
        - Được giải phóng khi kết thúc chương trình.
        1.4. Heap (Dynamic Memory Allocation)
        - Quyền truy cập là Read-Write
        - Được sử dụng để cấp phát bộ nhớ động như: malloc, calloc, realloc, new
        - Được giải phóng khi gọi hàm free, delete
        1.5. Stack (Automatic Variable Storage)
        - Quyền truy cập Read-Write
        - Được sử dụng để cấp phát tự động cho các biến local, input parameter của hàm...
        - Sẽ được giải phóng khi ra khỏi block code or hàm
    2. Sự giống nhau và khác nhau của Data và BSS
        2.1. Giống nhau
        - Đều có quyền truy cập Read-Write
        - Được giải phóng khi kết thúc chương trình
        2.2. Khác nhau
        - Với phân vùng nhớ Data các biến toàn cục và static phải được khởi tạo với 
          giá trị khác không còn với phân vùng nhớ BSS thì ngược lại, các biến toàn cục 
          và static được khởi tạo với giá trị bằng không or không cần khởi tạo.

## II: Macro & Function
    1. Macro
    - Được xử lý bởi Preprocessor (ở quá trình tiền xử lý trước quá trình biên dịch của compiler)
    - Ứng dụng để định nghĩa các hằng số, tạo ra các hàm viết tắt và tối ưu hóa mã lệnh.
    - Thay thế đoạn code đã được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó.
    2. Function
    - Được xử lý bởi Compiler.
    - Trước khi thấy hàm được gọi, compiler sẽ lưu con trỏ chương trình PC hiện tại vào 
      stack pointer (lưu những địa chỉ của con trỏ PC), chuyển PC tới hàm được gọi, thực hiện 
      hàm đó xong và lấy kết quả trả về, sau đó quay lại vị trí ban đầu trong stack trước khi 
      gọi hàm và tiếp tục thực hiện chương trình. 
    3. So sánh
    - Macro đơn giản chỉ thay thế đoạn code đã được define vào chỗ được gọi trước khi biên dịch.
    - Function phải tạo một function call, lưu địa chỉ trước khi gọi hàm vào stack pointer sau 
      đó mới thực hiện hàm, sau cùng là quay trở về địa chỉ trên stack pointer trước khi gọi hàm 
      và thực hiện tiếp chương trình.
    - Macro khiến code dài hơn rất nhiều, nhưng quá trình chạy lại nhanh hơn 
      (được xử lý trước khi mã chương trình được biên dịch)
    - Function phải gọi function call nên tốn thời gian hơn 
      (được xử lý khi chương trình đang chạy), nhưng code ngắn gọn hơn.
    - Macro thường hay dính lỗi đánh máy, cú pháp, trùng tên và khó phát hiện. Function dễ debug hơn.
    - Macro không cần định nghĩ kiểu dữ liệu của tham số, function phải định nghĩa kiểu dữ liệu 
      của tham số và trả về kiểu dữ liệu nào.
## III: Static
## IV: Struct & Union
## V: Pointer (Hàm, Void, Null)

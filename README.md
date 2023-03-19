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

    2. Fucntion
## III: Static
## IV: Struct & Union
## V: Pointer (Hàm, Void, Null)

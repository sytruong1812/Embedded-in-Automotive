# Embedded-in-Automotive

# I: Phân vùng nhớ (Memory Layout of C Program)

    1. Có 5 phân vùng nhớ trong RAM (Text, Data, BSS, Heap, Stack)

        1.1. Text Segment
        - Quyền truy cập là Read-only, chứa các lệnh để thực thi nên tránh sửa đổi (Contains executable instructions)
        - Chứa khai báo hằng số trong chương trình (.rodata)
        - Sharable
        1.2. Data Segment
        - Quyền truy cập Read-Wire
        - Chứa các biến toàn cục (global variable) or biến static với điều khiện là giá trị khởi tạo khác không.
        - Được giải phóng khi kết thúc chương trình.
        1.3. BSS (Uninitialized Data Segment)
        - Quyền truy cập Read-Write
        - Chứa các biến toàn cục (global variable) or biến static với giá trị khởi tạo bằng không or không khởi tạo.
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
    3. Sự giống nhau và khác nhau của Heap và Stack

# II: Macro & Function
# III: Static
# IV: Struct & Union
# V: Pointer (Hàm, Void, Null)

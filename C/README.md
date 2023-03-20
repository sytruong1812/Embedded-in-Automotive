## I: Phân vùng nhớ (Memory Layout of C Program)
    1. Có 5 phân vùng nhớ trong RAM (Text, Data, BSS, Heap, Stack) 
    [Image](https://www.google.com/imgres?imgurl=https%3A%2F%2Fwww.linhkien-36.com%2Fwp-content%2Fuploads%2F2020%2F05%2Fpage1-225px-Program_memory_layout.pdf.jpg&tbnid=3Me4JCNz0haUhM&vet=12ahUKEwjg1OKemer9AhWEc94KHVpwBKkQMygGegQIARBg..i&imgrefurl=https%3A%2F%2Fwww.linhkien-36.com%2Fphan-vung-nho-mcu%2F&docid=6QGRwJi-jitvVM&w=225&h=576&q=Ph%C3%A2n%20v%C3%B9ng%20nh%E1%BB%9B%20trong%20C&ved=2ahUKEwjg1OKemer9AhWEc94KHVpwBKkQMygGegQIARBg)
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
    2. So sánh Data và BSS
        2.1. Giống nhau
        - Đều có quyền truy cập Read-Write
        - Được giải phóng khi kết thúc chương trình
        2.2. Khác nhau
        - Với phân vùng nhớ Data các biến toàn cục và static phải được khởi tạo với 
          giá trị khác không còn với phân vùng nhớ BSS thì ngược lại, các biến toàn cục 
          và static được khởi tạo với giá trị bằng không or không cần khởi tạo.
    3. So sánh Heap và Stack
      3.1 Giống nhau
      - Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra 
        và lưu trữ trong RAM khi chương trình được thực thi.
      3.2 Khác nhau
      - Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào.. 
        Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
      - Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho các biến con trỏ được cấp phát động 
        bởi các hàm malloc - calloc - realloc/new.
      - Kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành. 
        Ngược lại kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do 
        đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
      - Vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu sẽ tự động bị hủy khi 
        hàm thực hiện xong công việc. Vùng nhớ Heap được quản lý bởi lập trình viên, dữ liệu 
        sẽ không tự động bị hủy mà phải tự tay hủy vùng nhớ bằng câu lệnh free/delete, 
      - Nếu liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap Overflow).

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
    - Macro thường hay dính lỗi đánh máy, trùng tên và không thể debug tìm 
      lỗi trong thời gian thực thi. Function dễ debug hơn.
    - Macro không cần định nghĩ kiểu dữ liệu của tham số, function phải định nghĩa kiểu dữ liệu 
      của tham số và trả về kiểu dữ liệu nào.
## III: Static
    1. Biến Static
    - Biến static là một biến có phạm vi truy cập chỉ trong một file, nghĩa là nó không thể được 
      truy cập từ các file khác. Từ khóa static dùng để khai báo các biến tĩnh trong (cục bộ) 
      và biến tĩnh ngoài (toàn bộ).
    2. Biến static cục bộ (biến tĩnh trong)
    - Khi biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất 
      và tồn tại suốt thời gian chạy chương trình.
    - Phạm vi sử dụng của biến static cục bộ chỉ giới hạn bên trong hàm mà nó khai báo. Tuy nhiên 
      giá trị của nó vẫn được giữ khi ra khỏi hàm và mỗi lần hàm được gọi, giá trị của biến chính 
      bằng giá trị tại lần gần nhất hàm được gọi.
    3. Biến static toàn cục (biến tĩnh ngoài)
    - Biến static toàn cục sẽ chỉ có thể truy cập và sử dụng trong file khai báo nó, các file khác 
      không có cách nào truy cập được (không thể extern như đối với biến ngoài). 
## IV: So sánh Struct & Union
    - Struct được gọi là kiểu dữ liệu người dùng định nghĩa. Dữ liệu của các member của struct được 
      lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các 
      member cộng lại và còn phụ thuộc vào bộ nhớ đệm (struct padding). 
    - Union cũng giống như Struct gồm nhiều member nhưng khác nhau ở chỗ các thành phần của các member 
      của Union được cấp phát một vùng nhớ chung. Size của Union bằng size của thành phần lớn nhất. 
      Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.
      Nói cách khác, việc gán giá trị cho các member của union trước, thì chỉ thành phần cuối cùng được 
      gián giá trị được sử dụng, các thành phần trước đó sẽ bị ghi đè. Được sử dụng để tiếp kiệm bộ nhớ.
## V: Pointer
    1. Pointer (kiểu *tên_con_trỏ;)
    - Con trỏ (Pointer) là những biến để lưu trữ địa chỉ của các biến khác. 
      Giá trị của 1 con trỏ là địa chỉ của 1 biến được gán cho nó.
    - Khi đã biết được địa chỉ của một biến thì ta chẳng những có thể sử dụng 
      giá trị của nó mà còn có thể gán cho nó một giá trị mới.
    - Vì có nhiều loại địa chỉ nên cũng có nhiều kiểu con trỏ (int, float, double...)
    2. Con trỏ hàm (Function pointers)
    - Con trỏ hàm dùng để chứa địa chỉ của hàm. Muốn vậy ta sử dụng phép gán tên hàm cho con trỏ hàm. 
      Để phép gán đúng thì kiểu hàm và kiểu con trỏ phải tương thích. Sau phép gán, ta có thể dùng tên con trỏ hàm thay thế tên hàm.
    - VD: 
        float max(float x, float y)
        {
          return (x > y ? x : y);
        } 
        // Khai báo và gán tên hàm max cho con trỏ hàm ptr
        float (*ptr)(float, float) = max;

    3. Mảng con trỏ (kiểu *tên_mảng[N])
    - Mảng con trỏ là một mảng mà mỗi phần tử của nó có thể chứa được một địa chỉ nào đó. 
      Cũng giống như con trỏ, mảng con trỏ có nhiều kiểu: mỗi phần tử của mảng kiểu con trỏ 
      kiểu int sẽ chứa được các địa chỉ kiểu int. Tương tự với kiểu char, float, double...
    - VD:
        char* ds[] = {
            "Ma sai",               //ds[0]
            "Nguyen Thi Anh",       //ds[1]
            "Nguyen Van Toan",      //ds[2]
            "Pham Van Tri",         //ds[3]
            "Do Hung Dung",         //ds[4]
            "Le Van Vu"             //ds[5]
        };

    3. Con trỏ void (void *ptr)
    - void *ptr là khai báo một con trỏ không kiểu. Đây là con trỏ đặc biệt, được sử dụng 
      để lưu trữ địa chỉ của bất kỳ biến nào trong chương trình. Vì nó là một con trỏ không kiểu, 
      nên nó có thể trỏ đến bất kỳ loại dữ liệu nào.
    - VD:
        int a = 10;
        float b = 2.5;
        char c = 'a';
        char d[5] = "hello";
        double f = 15.0;

        void *ptr = &a;

    4. Con trỏ Null
    - Là con trỏ không trỏ tới địa chỉ nào cả, khi khai báo con trỏ mà mình chưa biết 
      gán giá trị nào ta nên sử dụng con trỏ NULL.
    - VD: *ptr = NULL;

    5. Double Pointer (**pptr)
    - Con trỏ đôi dùng để lưu địa chỉ của con trỏ, nói cách khác giá trị của con trỏ 
      đôi **pptr là địa chỉ của con trỏ *ptr.
    - VD:
        int a = 10;
        int *ptr = &a;
        int **p_ptr = &ptr; 
    

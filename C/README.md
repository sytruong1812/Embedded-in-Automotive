## I: Phân vùng nhớ (Memory Layout of C Program)
  ### 1. Có 5 phân vùng nhớ trong RAM (Text, Data, BSS, Heap, Stack) 
  ![alt]( https://images.viblo.asia/eccce77d-6b51-4792-b544-a058f013b43d.png)
  #### 1.1. Text Segment
        - Quyền truy cập là Read-only, chứa các lệnh để thực thi nên tránh sửa đổi 
          (Contains executable instructions)
        - Chứa khai báo hằng số trong chương trình (.rodata)
        - Có thể chia sẻ (Sharable)
  #### 1.2. Data Segment
        - Quyền truy cập Read-Write
        - Chứa các biến toàn cục (global variable) or biến static 
          với điều khiện là giá trị khởi tạo khác không.
        - Được giải phóng khi kết thúc chương trình.
  #### 1.3. BSS (Uninitialized Data Segment)
        - Quyền truy cập Read-Write
        - Chứa các biến toàn cục (global variable) or biến static 
          với giá trị khởi tạo bằng không or không khởi tạo.
        - Được giải phóng khi kết thúc chương trình.
  #### 1.4. Heap (Dynamic Memory Allocation)
        - Quyền truy cập là Read-Write
        - Được sử dụng để cấp phát bộ nhớ động như: malloc, calloc, realloc, new
        - Được giải phóng khi gọi hàm free, delete
  #### 1.5. Stack (Automatic Variable Storage)
        - Quyền truy cập Read-Write
        - Được sử dụng để cấp phát tự động cho các biến local, input parameter của hàm...
        - Sẽ được giải phóng khi ra khỏi block code or hàm
  ### 2. So sánh Data và BSS
  #### 2.1. Giống nhau
        - Đều có quyền truy cập Read-Write
        - Được giải phóng khi kết thúc chương trình
  #### 2.2. Khác nhau
        - Với phân vùng nhớ Data các biến toàn cục và static phải được khởi tạo với 
          giá trị khác không còn với phân vùng nhớ BSS thì ngược lại, các biến toàn cục 
          và static được khởi tạo với giá trị bằng không or không cần khởi tạo.
  ### 3. So sánh Heap và Stack
  #### 3.1 Giống nhau
        - Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra 
          và lưu trữ trong RAM khi chương trình được thực thi.
  #### 3.2 Khác nhau
        - Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào.. 
          Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
        - Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho các biến con trỏ được cấp phát động 
          bởi các hàm malloc - calloc - realloc/new.
        - Kích thước:
          Bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành (VD: Win: 1MB, Linux: 8MB, tùy thuộc vào kiến trúc hệ điều hành)
          Ngược lại kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
        - Vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu sẽ tự động bị hủy khi 
          hàm thực hiện xong công việc. Vùng nhớ Heap được quản lý bởi lập trình viên, dữ liệu 
          sẽ không tự động bị hủy mà phải tự tay hủy vùng nhớ bằng câu lệnh free/delete.
        - Nếu liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap Overflow).
## II: Compiler
  ### 1. Quá trình Compiler
    - Quá trình Compiler là quá trình chuyển đổi từ ngôn ngữ bậc cao (C/C++, Python, Pascal...) sang ngôn ngữ máy.
    - Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được phải trải 
      qua một quá trình biên dịch dùng để chuyển đổi từ dạng mã nguồn sang dạng mã thực thi. 
      Quá trình này được chia là 4 giai đoạn chính
      + Giai đoạn tiền xử lý
      + Giai đoạn Compiler
      + Giai đoạn dịch mã Assembly
      + Giai đoạn liên kết (Linker)
  ![alt]( https://tapit.vn/wp-content/uploads/2020/03/Preprocessor.png)  
  ### 2. Giai đoạn (4 giai đoạn chính)
    - Giai đoạn tiền xử lý (Pre-processor)
      + Nhận mã nguồn, sau đó xóa bỏ tất cả comments
      + Các chỉ thị tiền xử lý #define (Macro), #include (file), biên dịch có điều kiện (#ifdef,..) cũng được xử lý ở giai đoạn này.
    - Giai đoạn Compiler (Dịch NNBC sang hợp ngữ Assembly)
      + Phân tích cú pháp của mã nguồn (NNBC) rồi chuyển chúng sang dạng ngôn ngữ bậc thấp hơn (Hợp ngữ - Assembly)
    - Giai đoạn dịch mã Assembly sang ngôn ngữ máy
      + Giai đoạn này chuyển mã Assembly sang ngôn ngữ máy (0 và 1)
      + Cuối cùng một tệp mã máy (.obj) được tạo ra trong hệ thống.
    - Giai đoạn liên kết (Linker)
      + Giai đoạn cuối mã máy của chương trình dịch từ nhiều nguồn (file .c hoặc file .lib) sẽ được liên kết lại với nhau
        tạo thành chương trình duy nhất (file .exe hay excutable). Và các mã máy của các lib được gọi trong chương trình chính cũng
        được đưa vào trong giai đoạn này.
      + Vì vậy trong giai đoạn này thì các lỗi liên quan đến việc gọi hàm hay sử dụng các biến mà không tồn tại sẽ 
        bị phát hiện. Hoặc các lỗi về viết chương trình chính mà không có hàm main() cũng sẽ bị phát hiện và thông báo.
## III: Macro & Function
  ### 1. Macro
      - Được xử lý ở quá trình tiền xử lý - Preprocessor (trước quá trình biên dịch của compiler)
      - Ứng dụng của Macro dùng để định nghĩa các hằng số, tạo ra các hàm viết tắt và tối ưu hóa mã lệnh.
      - Khi được xử lý trình biên dịch sẽ thay thế đoạn code đã được khai báo macro vào các vị trí mà macro đó được sử dụng.
      - VD: #define MY_NAME "Alex"
  ### 3. Inline Function
      - Được xử lý bởi compiler
      - Được khai báo với từ khóa inline
      - Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, trình biên dịch thực hiện thay thế vị trí gọi hàm 
        bằng nội dung hàm inline.
```C
inline return_type function_name(param){
...
}
  ```
  ### 4. Function
      - Được xử lý bởi Compiler.
      - Trước khi 1 Function được gọi, compiler sẽ lưu con trỏ PC (Program counter) hiện tại vào stack pointer 
        (lưu những địa chỉ của con trỏ PC), sau đó nhảy tới địa chỉ lưu function được gọi, thực hiện Function đó, 
        thực hiện xong sẽ lấy kết quả trả về, sau đó quay lại stack pointer lấy địa chỉ trước đó được lưu
        và tiếp tục thực hiện tiếp chương trình từ địa chỉ đó. 
  ### 5. So sánh Macro vs Function
      - Macro đơn giản chỉ thay thế đoạn code đã được define vào chỗ được gọi trước khi biên dịch.
      - Function phải tạo một function call, lưu địa chỉ trước khi gọi hàm vào stack pointer sau 
        đó mới thực hiện hàm, sau cùng quay trở về địa chỉ trên stack pointer trước khi gọi hàm 
        và thực hiện tiếp chương trình.
      - Macro khiến code dài hơn rất nhiều, nhưng quá trình chạy lại nhanh hơn 
        (được xử lý ở giai đoạn tiền xử lý trước khi mã chương trình được biên dịch)
      - Function phải gọi function call nên tốn thời gian hơn 
        (được xử lý khi chương trình đang chạy), nhưng code ngắn gọn hơn.
      - Macro thường hay dính lỗi đánh máy, trùng tên và không thể debug tìm lỗi trong thời gian thực thi. 
        Ngược lại Function dễ debug hơn...
      - Macro không cần định nghĩa kiểu dữ liệu của tham số, function phải định nghĩa kiểu dữ liệu 
        của tham số và trả về kiểu dữ liệu nào.
  ### 6. So sánh Inline Function vs Macro
      - Inline function là một hàm thực sự, trong khi macro là một thay thế văn bản.
      - Inline function được khai báo và định nghĩa như một hàm thông thường, được biên dịch và thực thi 
        như một phần của chương trình.
      - Macro là một thay thế văn bản được xử lý bởi trình biên dịch trước khi mã nguồn được biên dịch. 
        Trình biên dịch thay thế các macro bằng nội dung tương ứng trong mã nguồn trước khi biên dịch.
## IV: Static
  ### 1. Biến Static
      - Biến static có mức độ truy cập và phạm vi khác so với biến thông thường. 
      - Khi một biến được khai báo là static, nghĩa là biến đó chỉ được khởi tạo một lần duy nhất trong
        quá trình chạy chương trình và giá trị của nó được duy trì qua các lần gọi hàm.
      - Có 2 loại là biến tĩnh trong (cục bộ) và biến tĩnh ngoài (toàn bộ).
  ### 2. Biến static cục bộ (biến tĩnh trong)
      - Khi biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất 
        và tồn tại suốt thời gian chạy chương trình.
      - Phạm vi sử dụng của biến static cục bộ chỉ giới hạn bên trong hàm mà nó khai báo. Và giá trị của nó 
        vẫn được giữ khi ra khỏi hàm và mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
  ### 3. Biến static toàn cục (biến tĩnh ngoài)
      - Biến static toàn cục sẽ chỉ có thể truy cập và sử dụng trong file khai báo nó, các file khác 
        không có cách nào truy cập được (không thể extern như đối với biến thường). 
## V: So sánh Struct & Union
    - Giống nhau: Đều là kiểu dữ liệu người dùng tự định nghĩa. Và khai báo gồm nhiều member
    - Khác nhau: 
      + Kích thước: Kích thước của 1 STRUCT tối thiểu bằng kích thước các member cộng lại và còn phụ thuộc 
      vào bộ nhớ đệm (struct padding). Còn kích thước của UNION bằng kích thước của thành phần lớn nhất. 
      + Vùng nhớ: Dữ liệu của các member trong STRUCT được lưu trữ ở những vùng nhớ khác nhau. 
      Ngược lại trong UNION các member được cấp phát một vùng nhớ chung. Việc thay đổi nội dung 
      của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác. Nói cách khác, việc gán giá trị cho các 
      member của UNION trước, thì chỉ thành phần cuối cùng được gián giá trị được sử dụng, các thành phần trước 
      đó sẽ bị ghi đè. Vì vậy UNION được sử dụng để tiếp kiệm bộ nhớ.
## VI: Pointer
  ### 1. Bộ nhớ RAM
      - Đầu tiên khi nói về con trỏ thì nói qua về bộ nhớ RAM
      - Bộ nhớ RAM chứa rất nhiều ô nhớ, mỗi ô nhớ có kích thước 1 byte.
      - Mỗi ô nhớ có địa chỉ duy nhất được đánh số từ 0 trở đi
      - Tùy thuộc và các loại vi xử lý, nếu như vi xử lý 32bit thì có 2^32 địa chỉ có thể đánh số cho các ô nhớ trong RAM.
      - Khi khởi tạo 1 biến thì compiler sẽ lấy ra một vùng nhớ để lưu giá trị của biến đó và gán địa chỉ của vùng nhớ đó  
        cho tên biến. Khi gọi biến đó thì giá trị của biến đó sẽ được lấy ra
  ### 2. Pointer (kiểu *tên_con_trỏ;) 
  ![alt]( http://4.bp.blogspot.com/-ZEtJgndAc-0/VcmkqmDAkEI/AAAAAAAAOx4/Rafu_VigO8w/s1600/bieudien_contro.png)

      - Con trỏ (Pointer) là những biến để lưu trữ địa chỉ của các biến khác. 
        Giá trị của 1 con trỏ là địa chỉ của 1 biến được gán cho nó.
      - Con trỏ chỉ lưu địa chỉ nên kích thước của các con trỏ như nhau, kích thước này phụ thuộc kiến trúc của 
        vi xử lý (16bit/8: 2byte; 32bit/8: 4byte; 64bit/8: 8byte)
      - Khi đã biết được địa chỉ của một biến thì ta chẳng những có thể sử dụng giá trị của nó mà còn có thể gán cho nó một giá trị mới.
      - Vì có nhiều loại địa chỉ nên cũng có nhiều kiểu con trỏ (int, float, double...)
      - Con trỏ chỉ có thể lưu trữ địa chỉ của các biến có cùng kiểu dữ liệu, trừ con trỏ void. Con trỏ void một con trỏ
        không kiểu nên nó có thể lưu được các địa chỉ của các biến có địa chỉ khác nhau.
      - Khi khởi tạo 1 con trỏ mà không gán giá trị, thì con trỏ đó sẽ trỏ tới một vùng nhớ ô nhớ bất kỳ trong RAM, nên con trỏ đó sẽ 
        gây nhiễu, làm thực thi sai chương trình. Để tránh điều đó thì khi khai báo con trỏ mà mình chưa biết gán giá trị nào 
        ta nên gán giá trị NULL cho con trỏ đó
      - Con trỏ NULL là con trỏ không trỏ tới địa chỉ nào cả, con trỏ NULL là con trỏ lưu địa chỉ 0x00000000 (Tức địa chỉ bộ nhớ 0)
      - Khi sử dụng xong 1 con trỏ ta nên gán lại giá trị cho con trỏ đó là NULL để tránh lỗi rò rỉ bộ nhớ.
  ### 3. Con trỏ hàm (kiểu (*ptr)(kiểu, kiểu))
      - Con trỏ hàm dùng để chứa địa chỉ của hàm. Muốn vậy ta sử dụng phép gán tên hàm cho con trỏ hàm. 
        Để phép gán đúng thì kiểu hàm và kiểu con trỏ phải tương thích. Sau phép gán, ta có thể dùng 
        tên con trỏ hàm thay thế tên hàm.
      - VD: 
          float max(float x, float y)
          {
            return (x > y ? x : y);
          } 
          // Khai báo và gán tên hàm max cho con trỏ hàm ptr
          float (*ptr)(float, float) = max;
  ### 4. Mảng con trỏ (kiểu *tên_mảng[N])
      - Mảng con trỏ là một mảng mà mỗi phần tử của nó có thể chứa được một địa chỉ nào đó. Cũng giống như con trỏ, 
        mảng con trỏ có nhiều kiểu: mỗi phần tử của mảng kiểu con trỏ kiểu int sẽ chứa được các địa chỉ kiểu int.
        Tương tự với kiểu char, float, double...
      - VD:
          char* ds[] = {
              "Ma sai",               //ds[0]
              "Nguyen Thi Anh",       //ds[1]
              "Nguyen Van Toan",      //ds[2]
              "Pham Van Tri",         //ds[3]
              "Do Hung Dung",         //ds[4]
              "Le Van Vu"             //ds[5]
          };
  ### 5. Con trỏ void (void *ptr)
      - void *ptr là khai báo một con trỏ không kiểu. Đây là con trỏ đặc biệt, được sử dụng để lưu trữ địa chỉ của bất kỳ 
        biến nào trong chương trình. Vì nó là một con trỏ không kiểu, nên nó có thể trỏ đến bất kỳ loại dữ liệu nào.
      - VD:
          int a = 10;
          float b = 2.5;
          char c = 'a';
          char d[5] = "hello";
          double f = 15.0;

          void *ptr = &a;
  ### 6. Con trỏ Null
      - Là con trỏ không trỏ tới địa chỉ nào cả, con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. 
        Tức địa chỉ bộ nhớ 0, khi khai báo con trỏ mà mình chưa biết gán giá trị nào ta nên sử dụng con trỏ NULL.
      - Không sử dụng con trỏ NULL: Tránh sử dụng con trỏ NULL trong ứng dụng vì nó có thể dẫn đến lỗi runtime hoặc crash hệ thống.
      - VD: *ptr = NULL;
  ### 7. Pointer to pointer - Double Pointer (**pptr)
      - Con trỏ đôi dùng để lưu địa chỉ của con trỏ, nói cách khác giá trị của con trỏ 
        đôi **pptr là địa chỉ của con trỏ *ptr.
      - VD:
          int a = 10;
          int *ptr = &a;
          int **p_ptr = &ptr; 
![alt]( https://qph.cf2.quoracdn.net/main-qimg-95a55bb04f7e48019f9f606dacdd9756)
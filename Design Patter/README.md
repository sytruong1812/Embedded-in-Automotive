## DESIGN PATTER
- Design patterns là 1 đoạn mô tả, hoặc 1 khuôn mẫu để giải quyết 1 vấn đề nào đó. Nó không phải là thiết kế cuối cùng.
- Design Pattern được tạo ra để giải quyết vấn đề, chứ không phải để phức tạp hóa nó.
- Design Pattern giúp code được tối ưu hóa, dễ tái sử dụng, dễ hiểu, dễ nâng cấp sửa chữa.
- Design Pattern có liên quan chặt chẽ đến 2 nguyên lý thiết kế đối tượng: về interface và về composition ở trên.
![alt](https://onetech.jp/wp-content/uploads/2021/12/Design-Pattern-gom-nhung-loai-nao.jpg)
### I. Singleton Pattern
- Singleton là một mẫu thiết kế (design pattern) trong lập trình hướng đối tượng, được sử dụng để giới hạn việc tạo ra 
  chỉ một đối tượng duy nhất của một lớp và cung cấp một điểm truy cập toàn cục để truy xuất đối tượng này. Mục tiêu của 
  Singleton là đảm bảo rằng chỉ có một thể hiện (instance) duy nhất của lớp được tạo ra và cho phép các đối tượng khác 
  truy cập nó thông qua một phương thức tĩnh (static).
### II. Factory Pattern
- Factory Design Pattern là một mẫu thiết kế (design pattern) trong lập trình hướng đối tượng, được sử dụng để tạo ra 
  các đối tượng mà không cần xác định rõ lớp cụ thể của chúng. Nó tách quyết định về việc tạo đối tượng ra khỏi client 
  code, cho phép linh hoạt trong việc thay đổi lớp cụ thể của đối tượng được tạo ra.
- Cách hoạt động của Factory Design Pattern như sau:
    1. Một interface hoặc lớp cơ sở trừu tượng được xác định, mô tả phương thức chung để tạo đối tượng.
    2. Các lớp con cụ thể được triển khai từ interface hoặc lớp cơ sở, mỗi lớp con đại diện cho một cách cụ thể để tạo đối tượng.
    3. Factory class (lớp Factory) chịu trách nhiệm tạo đối tượng dựa trên yêu cầu của client code. Factory class cung 
       cấp phương thức tạo đối tượng và quyết định lớp cụ thể nào được sử dụng.
### III. Abstract Factory Pattern
- Abstract Factory Design Pattern là một mẫu thiết kế (design pattern) trong lập trình hướng đối tượng, được sử dụng để 
  tạo ra các đối tượng liên quan hoặc có quan hệ với nhau mà không cần chỉ định rõ lớp cụ thể của chúng. Nó tách quyết 
  định về việc tạo đối tượng ra khỏi client code và cung cấp một giao diện chung để tạo các họ đối tượng liên quan.
- Cách hoạt động của Abstract Factory Design Pattern như sau:
    1. Định nghĩa một giao diện trừu tượng (Abstract Factory) để khởi tạo các đối tượng. Giao diện này chứa các phương 
       thức tạo ra các đối tượng liên quan hoặc có quan hệ với nhau.
    2. Định nghĩa các lớp cụ thể (Concrete Factories) triển khai giao diện Abstract Factory để cung cấp triển khai cụ 
       thể của phương thức tạo đối tượng.
    3. Định nghĩa các lớp trừu tượng (Abstract Products) mô tả các đối tượng liên quan hoặc có quan hệ với nhau.
    4. Định nghĩa các lớp cụ thể (Concrete Products) triển khai các lớp trừu tượng để cung cấp triển khai cụ thể của các đối tượng.
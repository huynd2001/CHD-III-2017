# Lời giải Cúp Huynh Đệ 3.0

## A. Dãy nhị phân đẹp
Dễ dàng nhận thấy rằng số thao tác cần thực hiện là cố định, và trạng thái cuối cùng là khi tất cả các bit 1 đều nằm ở bên trái tất cả các bit 0. Vì vậy, không mất tính tổng quát, ta sẽ di chuyển lần lượt các bit 0 từ trái sang. Nhận thấy rằng sau mỗi lần di chuyển bit 0 như vậy, số bit 1 mà bit 0 tiếp theo phải di chuyển qua sẽ nhân đôi lên. Như vậy, ta có thể thấy lời giải sẽ là di chuyển từ phải sang trái và cập nhật đáp án mỗi khi gặp bit 0 và cập nhật số bit 1 mà bit 0 tiếp theo cần đi qua.

**Độ phức tạp : O(N)**

## B. Nỗi nhớ rừng
Đây là bài xử lý xâu cơ bản : Trong lúc chạy vòng lặp từ đầu đến cuối, đếm số xâu con "rung" xuất hiện và cập nhật vào kết quả. Tuy vậy, với trường hợp xâu test cho là "LoveForest" thì sẽ cần phải in ra "Camon" như trong đề bài đã đề cập đến.

**Độ phức tạp : O(N)**

## C. Cách chọn binh đoàn hùng mạnh (nhất)
Khi nhìn đến việc cần tìm đoạn con có giá trị lớn nhất, ta nghĩ ngay đến việc lưu tổng dồn. Ta sẽ lưu 2 mảng tổng dồn riêng với vị trí i như sau :

+ `su[i][0] = ... + a[i-1] - a[i];`
+ `su[i][1] = ... - a[i-1] + a[i];`

Như thế, khi chạy vòng lặp đến i, ta luôn lưu lại mảng tổng dồn bé nhất trước đấy cho hai trường hợp i lẻ và i chẵn tương ứng là mi[1] và mi[0]. Từ đấy, kết quả sẽ được cập nhật bằng `su[i][0]-mi[i%2]` và `su[i][1]-mi[1-i%2]`.

**Độ phức tạp : O(N)**

## D. Cách chọn tàu vũ trụ đẹp (nhất)
t1<t2<t3<t4 và công thức toán `a[t1]+a[t2]*(a[t3]^a[t4])` và các số đều dương, cho ta nhận thấy vấn đề rằng có thể cố định t2, và đáp án sẽ được cập nhật bằng giá trị `a[t1]` lớn nhất đằng trước t2 và giá trị `a[t3]^a[t4]` lớn nhất nằm sau t2. Ta có thể chuẩn bị trước với mỗi t2 giá trị `a[t1]` lớn nhất trong O(N) và giá trị `a[t3]^a[t4]` lớn nhất trong O(N^2).
**Độ phức tạp : O(N^2)**

## E. Cách diệt gián nhanh
Do các số đều là số nguyên tố nên ta sẽ xét tất cả các tập con các số trong N số đã cho, và đếm xem có bao nhiêu số là bội của tích đấy mà nhỏ hơn M. Đáp án sẽ được cộng thêm nếu tập có lẻ phần tử, và sẽ được trừ đi nến tập con có chẵn phần tử. Việc này có thể được quản lý bằng việc for bitmask hoặc backtrack tập con.

**Độ phức tạp : O(2^N*N) (O(2^N) nếu backtrack)**

## F. Bài toán thế kỉ
Ta sẽ sắp xếp lại các số theo thứ tự. Số x sẽ đứng trước số y nếu như khi ghép x lên trước y thì sẽ tạo ra được số lớn hơn là khi ghép y trước x. VD : 9 sẽ được sắp trước 92 vì 992 lớn hơn 929.
Để sắp xếp lại dãy trên bằng C++, ta có thể tự cài lại Merge Sort và thay đổi cách so sánh hai số, hoặc sử dùng hàm sort trong C++.

Giả sử muốn sắp xếp mảng N phần tử nguyên a[1] đến a[N] theo cách trên, ta có thể viết thành `sort(a+1,a+N+1,cmp);` với cmp là một hàm viết ở ngoài trả về dưới dạng boolean :
```c++
bool cmp(int x,int y)
{
  ...
}
```
Ở bên trong ta sẽ thực hiện việc so sánh. Nếu `return 1;` thì x sẽ được đặt trước y, nếu không thì y sẽ được đặt trước x.
Như vậy, việc sắp xếp là hoàn tất. Ta chỉ cần in ra các số theo thứ tự đã sắp xếp là được.

**Độ phức tạp : O(N \* logN)**

## G. Đơn hàng lỗi
Ta sẽ đọc hết tất cả các số có thể đọc được vào, trong quá trình đọc có thể thực hiện tính tổng luôn. Dễ thấy rằng giá trị cần phải trừ đi để ra đáp số đúng là số số đã đọc vào trừ đi 1.

**Độ phức tạp : O(N)**

## H. Trò chơi hàng năm
Đầu tiên, rõ rằng dãy hoán vị hoàn toàn có thể được sắp xếp lại bằng cách chỉ dùng thao tác 1, do vậy không bao giờ có trường hợp phải in ra -1. Ngoài ra, khi thực hiện bất kì thao tác nào thì chỉ có hai số bị đổi chỗ cho nhau. Gọi vị trí của số thứ i trong hoán vị nhận được là pos[i]. Ta có nhận xét rằng khi sử dụng thao tác 2 để đổi chỗ hai số i và j, pos[i] và pos[j] không thay đổi tính chẵn lẻ. Do vậy, nếu chỉ sử dụng thao tác 2 thì sẽ có một vài trường hợp không thể đổi được (VD : Khi pos[1]=2). Với nhận xét này, ta dễ dàng thấy rằng kết quả chính là một nửa số giá trị i mà `pos[i] % 2 != i % 2`.

**Độ phức tạp : O(N)**

## I. Trò ảo thuật kì diệu
Dễ dàng nhận thấy cách tham của bài này là khi xét đến tập bài i, ta sẽ ghép đôi hết chúng lại với nhau, nếu còn thừa sẽ chuyển sang tập bài i+1 nếu tập i+1 còn bài trong lúc for i chạy từ 1 đến N.

**Độ phức tạp : O(N)**

## J. Hàng rào
Xét dãy hàng rào độ dài i. Nếu ta muốn đưa thêm thanh hàng rào độ dài i+1 vào thì chỉ có hai cách thêm vào là thêm vào đầu và thêm vào cuối. Vì vậy, số cách xây hàng rào độ dài i bằng 2 lần số cách xây hàng rào độ dài i-1. Đáp án sẽ là 2^(N-1). Lưu ý modulo 1e8+7.

**Độ phức tạp : O(N)**

## K. Chia bom IPTD-949
Ta sẽ cần kiểm tra xem có tồn tại mảng x[] sao cho
+ `x[1] * a[1] + x[2] * a[2] + ... + x[N] * a[N] == M;`
+ `x[1] > x[2] > x[3] > ... > x[N] > 0;`

Nhận thấy rằng nếu cho 1 quả bom vào mỗi khoang của tàu i thì tất cả các tàu từ 1 đến i-1 đều phải được thêm ít nhất 1 quả bom vào mỗi khoang. Vì vậy, đây là bài toán Knapsack mà ở đây các đồ vật có giá trị là mảng tổng dồn thay vì mảng a[]. Gọi tổng các số trong khoảng từ 1 đến i là su[i]. dp[i][j] sẽ được cập nhật bởi dp[i][j-su[i]] và dp[i-1][j-su[i]], khởi tạo riêng cho dp[0][0] .

**Độ phức tạp : O(N \* M)**

## L. Điểm tập kết
Dễ nhận thấy rằng tọa độ x và y có thể được xử lý riêng biệt. Bây giờ bài toán được chuyển về thành trên một dãy số. Ta thấy rằng vị trí tập kết là trung vị của dãy số sau khi được sắp xếp.

**Độ phức tạp : O(N \* logN)**

## M. Tuyển tập vũ khí chiến tranh
Tại cột i, ta sẽ tính xem diện tích lớn nhất của một hình chữ nhật có cạnh trái ở cột i sẽ là bao nhiêu. Ở cột i, ta có thể tính được đoạn 1 dài nhất về phía bên phải ở mỗi hàng tính từ cột i là bao nhiêu bằng việc tính toán trong lúc chạy vòng lặp từ phải sang trái. Sau khi tính được các giá trị này cho mỗi hàng, gọi là r[j], ta thấy rằng có thể tính với mọi giá trị có thể của r[j] thì số hàng nhiều nhất mà hình chữ nhật có X cột ở cột i có thể có là bao nhiêu, hay chính là số hàng mà giá trị r[j] lớn hớn X. May thay, giá trị này không vượt quá M nên ta có thể chạy vòng lặp để đếm và cập nhật vào kết quả.

**Độ phức tạp : O(M \* (M + N))**

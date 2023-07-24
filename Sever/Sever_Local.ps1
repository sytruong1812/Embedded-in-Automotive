# PowerShell.exe -ExecutionPolicy Unrestricted -File ./file.ps1
# Thiết lập địa chỉ và cổng cho HTTP server
$hostname = "localhost"
$port = 6060

# Thư mục chứa các tệp bạn muốn hosting
$filesDirectory = "C:\Users\SY TRUONG\Downloads\Embedded in Automotive"

# Tạo URL cho HTTP server
$url = "http://${hostname}:${port}/"

# Tạo HTTP listener
$listener = New-Object System.Net.HttpListener
$listener.Prefixes.Add($url)

# Bắt đầu lắng nghe yêu cầu HTTP
$listener.Start()
Write-Host "HTTP server running on $url"

try {
    while ($listener.IsListening) {
        $context = $listener.GetContext()
        $request = $context.Request
        $response = $context.Response

        # Lấy đường dẫn yêu cầu từ trình duyệt
        $requestedPath = $request.Url.LocalPath

        # Xác định đường dẫn tuyệt đối của tệp được yêu cầu
        $filePath = Join-Path $filesDirectory $requestedPath.Substring(1)

        # Kiểm tra xem đường dẫn yêu cầu là "/" và tệp "index.txt" tồn tại
        if ($requestedPath -eq "/" -and (Test-Path $filePath -PathType Leaf)) {
            # Đọc nội dung file "index.txt"
            $fileContent = Get-Content $filePath

            # Chuyển đổi nội dung thành mảng byte
            $content = [System.Text.Encoding]::UTF8.GetBytes($fileContent)

            # Thiết lập các thông số cho phản hồi HTTP
            $response.StatusCode = 200
            $response.ContentType = "text/plain"
            $response.ContentLength64 = $content.Length

            # Ghi nội dung vào phản hồi HTTP
            $response.OutputStream.Write($content, 0, $content.Length)
        } else {
            # Nếu đường dẫn yêu cầu không phải "/" hoặc tệp "index.txt" không tồn tại, trả về mã lỗi 404 - Not Found
            $response.StatusCode = 404
        }

        # Đóng phản hồi HTTP
        $response.Close()
    }
} catch {
    Write-Host "Error: $_"
}

# Dừng HTTP listener khi kết thúc
$listener.Stop()

# Giải phóng tài nguyên
$listener.Close()

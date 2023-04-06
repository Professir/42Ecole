## 17.09.2022

---

### **News**

- Yeni dosya düzeni

- Test yapabileceğimiz dosyayı yarattım

Yeni dosya düzeni daha rahat. Tek farkı kütüphane çağırırken

```C
#include "../lib.h"
```

gibi çağırman gerekecek.

Test dosyasında ise bütün projeyi gcc lemeden ve 42 formatına takılmadan dosyaları oluşturup test edebiliyorsun. Tek isteğım benim testleri çok değiştirme, istersen kendi testlere kopyala öyle değiştir.
  
### **Yapılması gereken**

get_map fonk doğru almıyor. Veriyi doğru çekip, 2d arrraya doğru atmamız gerek. Bunu için get_next_lıne a benzeyen fonksiyon yaratıp, her bir satırı 2d arrayın ayrı bir eleman olarak kaydetmemiz gerek.

```C
char **g_maps = get_map(open("map.ber", O_RDONLY));
printf("%s", g_maps);
```


```bash
# Output:
[skel@dhcppc2 tests]$ ./a.out 
�"�[skel@dhcppc2 tests]$
```

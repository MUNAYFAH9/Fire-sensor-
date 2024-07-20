//E-INNOVATORS
//fire alarm //

const int buzzerPin = 12; // دبوس خرج الصفارة
const int flamePin = 11; // دبوس إدخال مستشعر اللهب
int Flame = HIGH; // متغير لقراءة إشارة مستشعر اللهب
int duration = 5; // مدة تشغيل الصفارة بالثواني
unsigned long startTime; // وقت بدء تشغيل الصفارة

#include <Time.h> // تضمين مكتبة Time لاستخدام وظيفة millis()

void setup() {
  pinMode(buzzerPin, OUTPUT); // تعيين دبوس الصفارة كمخرج
  pinMode(flamePin, INPUT); // تعيين دبوس مستشعر اللهب كمدخل
  Serial.begin(9600); // إنشاء اتصال تسلسلي (اختياري)
}

void loop() {
  Flame = digitalRead(flamePin); // قراءة إشارة مستشعر اللهب
  if (Flame == LOW) { // إذا تم استشعار النار
    playAlarmForDuration(duration); // شغل الصفارة لـ 5 ثوانٍ
  } else {
    digitalWrite(buzzerPin, LOW); // أطفئ الصفارة
  }
}

void playAlarmForDuration(int duration) {
  startTime = millis(); // احفظ وقت بدء التشغيل
  digitalWrite(buzzerPin, HIGH); // شغل الصفارة
  while (millis() - startTime < duration * 1000) { // انتظر المدة المحددة
    // لا تفعل أي شيء
  }
  digitalWrite(buzzerPin, LOW); // أطفئ الصفارة
}

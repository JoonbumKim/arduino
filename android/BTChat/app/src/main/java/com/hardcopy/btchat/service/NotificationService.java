package com.hardcopy.btchat.service;

import android.app.Notification;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.service.notification.NotificationListenerService;
import android.service.notification.StatusBarNotification;
import android.support.v4.content.LocalBroadcastManager;
import android.util.Log;

import java.io.ByteArrayOutputStream;
import java.sql.Timestamp;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;


public class NotificationService extends NotificationListenerService {

    Context context;

    @Override

    public void onCreate() {

        super.onCreate();
        context = getApplicationContext();
        Log.i("NotificationService", "ON");
    }
    @Override

    public void onNotificationPosted(StatusBarNotification sbn) {
        String pack = sbn.getPackageName();
        String ticker ="";

        Log.i("Package",pack);
        if(sbn.getNotification().tickerText !=null) {
            ticker = sbn.getNotification().tickerText.toString();
        }
        Bundle extras = sbn.getNotification().extras;
        String title = extras.getString("android.title");
        CharSequence cs = extras.getCharSequence("android.text");
        String text = "";
        if(cs != null) {
            text = extras.getCharSequence("android.text").toString();


            Log.i("Ticker",ticker);
            Log.i("Title",title);
            Log.i("Text",text);

            int id1 = extras.getInt(Notification.EXTRA_SMALL_ICON);
            Bitmap id = sbn.getNotification().largeIcon;

            Intent msgrcv = new Intent("Msg");
            msgrcv.putExtra("package", pack);
            msgrcv.putExtra("ticker", ticker);
            msgrcv.putExtra("title", title);
            msgrcv.putExtra("text", text);
            if(id != null) {
                ByteArrayOutputStream stream = new ByteArrayOutputStream();
                id.compress(Bitmap.CompressFormat.PNG, 100, stream);
                byte[] byteArray = stream.toByteArray();
                msgrcv.putExtra("icon",byteArray);
            }
            LocalBroadcastManager.getInstance(context).sendBroadcast(msgrcv);
        }
    }

    @Override

    public void onNotificationRemoved(StatusBarNotification sbn) {
        Log.i("Msg","Notification Removed");

    }
}

package com.hardcopy.btchat.service;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.support.v4.content.LocalBroadcastManager;
import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;

import java.sql.Timestamp;
import java.util.Timer;
import java.util.TimerTask;

/**
 * Created by mukesh on 19/5/15.
 */
public class ServiceReceiver extends BroadcastReceiver {
    TelephonyManager telephony = null;
    String _incomingNumber = "";
    int _state = 0;
    int flag = 0;
    @Override
    public void onReceive(final Context context, Intent intent) {

        telephony = (TelephonyManager) context.getSystemService(Context.TELEPHONY_SERVICE);
        telephony.listen(new PhoneStateListener() {
            @Override
            public void onCallStateChanged(int state, String incomingNumber) {
                super.onCallStateChanged(state, incomingNumber);

//                TelephonyManager.CALL_STATE_RINGING : 벨소리 울리는 중
//                TelephonyManager.CALL_STATE_OFFHOOK : 통화 시작
//                TelephonyManager.CALL_STATE_IDLE : 통화 끝, 벨소리 울리는 중에 통화 거절
                _state = state;
                _incomingNumber = incomingNumber;

                System.out.println("ServiceReceiver");
                System.out.println("state :: " + state);
                System.out.println("now :: " + new Timestamp(System.currentTimeMillis()));
                System.out.println("incomingNumber : " + _incomingNumber);
                System.out.println("flag : " + flag);
                if(state == 1 && flag == 0) { // 최초 한번 보낸다.
                    flag++;
                    Intent msgrcv = new Intent("Msg");
                    //msgrcv.putExtra("package", "");
                    //msgrcv.putExtra("ticker", _incomingNumber);
                    msgrcv.putExtra("title", "");
                    msgrcv.putExtra("text", _incomingNumber);

                    LocalBroadcastManager.getInstance(context).sendBroadcast(msgrcv);

                    new android.os.Handler().postDelayed(
                            new Runnable() {
                                public void run() {
                                    int state = telephony.getCallState();
                                    if (state == 1) {
                                        System.out.println("postDelayed");
                                        flag = 0;
                                        onCallStateChanged(_state, _incomingNumber);
                                    }
                                }
                            },
                            5000);
                }
            }
        }, PhoneStateListener.LISTEN_CALL_STATE);
    }
}
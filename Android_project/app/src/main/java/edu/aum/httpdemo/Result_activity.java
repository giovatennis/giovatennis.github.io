package edu.aum.httpdemo;

import androidx.appcompat.app.AppCompatActivity;
import edu.aum.httpdemo.R;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class Result_activity extends AppCompatActivity {
    private TextView mResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result);
        mResult = (TextView) findViewById(R.id.result_text);
        Intent i = getIntent();
        String result = i.getExtras().getString("result");
        if(result != null){
          
                mResult.setText(result);
          
        }


    }
}

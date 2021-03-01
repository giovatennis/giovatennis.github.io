package edu.aum.httpdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class MainActivity extends AppCompatActivity {

    private Button mButton;
    private TextView mTextView;
    private EditText mEditText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mButton = (Button) findViewById(R.id.button);
        mTextView = (TextView) findViewById(R.id.res_text_view);
        mEditText = (EditText) findViewById(R.id.input_search);

        mButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String text = ""; // this gets the whole input, i need to cut it in pieces (title, type ,year) and the concat with the url
                text = mEditText.getText().toString();
                String text1 = "";
                text1 = text.substring(0, text.indexOf(','));
                System.out.println(text1);
                text = text.substring(text.indexOf(",") + 1);
                text.trim();
                System.out.println(text); //this has type,year
                String text2 = "";
                text2 = text.substring(0, text.indexOf(','));
                System.out.println(text2);
                text = text.substring(text.indexOf(",") + 1);
                text.trim();
                System.out.println(text);

                // Instantiate the RequestQueue.
                RequestQueue queue = Volley.newRequestQueue(MainActivity.this);
                String url1 = "http://www.omdbapi.com/?apikey=39c77b5b&t=";
                String url2 = "&type=";
                String url3 = "&y=";
                String url = "";
                url = url.concat(url1).concat(text1).concat(url2).concat(text2).concat(url3).concat(text);

                // Request a string response from the provided URL.
                StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                        new Response.Listener<String>() {
                            @Override
                            public void onResponse(String response) {
                                // Display the first 500 characters of the response string.
                               // mTextView.setText("Response is: " + response);
                                Intent intent = new Intent(MainActivity.this, Result_activity.class);
                                //JSONArray jsonArray = new JSONArray();
                                JSONObject o = new JSONObject();
                                try {
                                    o.put("stringResult", response);

                                } catch (JSONException e) {
                                    e.printStackTrace();
                                }

                                intent.putExtra("result",o.toString());
                                System.out.println(response);
                                startActivity(intent);

                            }
                        }, new Response.ErrorListener() {
                    @Override
                    public void onErrorResponse(VolleyError error) {
                        mTextView.setText("That didn't work!");
                    }
                });

                // Add the request to the RequestQueue.
                queue.add(stringRequest);
                //up to now i get the big JSON text but on the same activity, find the way to move it to
                //activity result
                //System.out.println(response);




            }
        });
    }
}

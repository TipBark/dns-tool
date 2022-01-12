package com.tip.demo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.tip.demo.databinding.ActivityMainBinding;
import com.tip.net.dns.DNSUtil;

public class MainActivity extends AppCompatActivity {

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        binding.sampleBtn.setOnClickListener(v -> {
            binding.sampleText.setText(DNSUtil.getHostByName("www.baidu.com"));
        });
    }

}
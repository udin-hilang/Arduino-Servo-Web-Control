<!String html = R"rawliteral(>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>KONTROL SERVO</title>
    <!-- Import font Orbitron untuk kesan futuristik -->
    <link href="https://fonts.googleapis.com/css2?family=Orbitron:wght@500;700&display=swap" rel="stylesheet">
    <style>
        body {
            background: radial-gradient(circle at center, #0a0a2a 0%, #000000 100%);
            color: #00f3ff;
            font-family: 'Orbitron', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            overflow: hidden;
        }

        /* Tampilan panel utama bergaya high-tech */
        .panel {
            background: rgba(10, 14, 31, 0.7);
            border: 2px solid #00f3ff;
            border-radius: 15px;
            box-shadow: 0 0 20px rgba(0, 243, 255, 0.4), inset 0 0 15px rgba(0, 243, 255, 0.2);
            padding: 40px 50px;
            text-align: center;
            backdrop-filter: blur(10px);
            width: 350px;
        }

        .header h1 {
            margin: 0 0 30px 0;
            font-size: 28px;
            letter-spacing: 2px;
            text-shadow: 0 0 10px #00f3ff, 0 0 20px #00f3ff;
        }

        /* Container untuk slider dan teks */
        .slider-container {
            display: flex;
            flex-direction: column;
            align-items: center;
            gap: 20px;
        }

        /* Customisasi Tampilan Range Slider */
        input[type=range] {
            -webkit-appearance: none;
            width: 100%;
            background: transparent;
        }

        input[type=range]:focus {
            outline: none;
        }

        /* Track (Jalur Slider) */
        input[type=range]::-webkit-slider-runnable-track {
            width: 100%;
            height: 8px;
            cursor: pointer;
            background: #002244;
            border-radius: 5px;
            border: 1px solid #00f3ff;
            box-shadow: 0 0 10px rgba(0, 243, 255, 0.3);
        }

        /* Thumb (Tombol Slider) */
        input[type=range]::-webkit-slider-thumb {
            height: 24px;
            width: 24px;
            border-radius: 50%;
            background: #ffffff;
            cursor: pointer;
            -webkit-appearance: none;
            margin-top: -9px;
            box-shadow: 0 0 15px #00f3ff, 0 0 30px #00f3ff;
            border: 2px solid #00f3ff;
            transition: transform 0.1s;
        }

        input[type=range]::-webkit-slider-thumb:hover {
            transform: scale(1.2);
            background: #00f3ff;
        }

        /* Display Nilai Derajat */
        .value-display {
            font-size: 40px;
            font-weight: 700;
            color: #fff;
            text-shadow: 0 0 10px #00f3ff, 0 0 20px #00f3ff;
            background: rgba(0, 243, 255, 0.1);
            padding: 10px 30px;
            border-radius: 8px;
            border: 1px solid rgba(0, 243, 255, 0.3);
        }
    </style>
</head>
<body>
    <div class="panel">
        <div class="header">
            <h1>KONTROL SERVO</h1>
        </div>
        <div class="slider-container">
            <input type="range" min="0" max="180" value="90" id="speedSlider">
            <div class="value-display">
                <span id="speedValue">90</span>&deg;
            </div>
        </div>
    </div>

    <script>
        const slider = document.getElementById("speedSlider");
        const output = document.getElementById("speedValue");

        // oninput jalan saat slider sedang ditarik (buat animasi UI biar responsif)
        slider.oninput = function() {
            output.innerHTML = this.value;
        }

        // onchange jalan saat slider dilepas (biar ga nyepam request ke server/mikrokontroler)
        slider.onchange = function() {
            fetch("/speed?value=" + this.value)
                .then(response => console.log("Perintah terkirim: " + this.value + " derajat"))
                .catch(error => console.error("Gagal mengirim perintah:", error));
        }
    </script>
</body>
</html>
<!)rawliteral";>
String html = R"rawliteral(
<html>
    <head>
        <title>KONTROL SERVO</title>
        <style>
            body {
                background-color: rgb(0, 0, 35);
            }
            .header {
                font-family: Arial;
                font-weight: bold;
                font-style: italic;
                font-size: 30px;
                background-color: rgb(14, 14, 43);
                color: white;
                margin-top: 0;
            }

            .slider {
                display: flexbox;
                background-color: rgb(14, 14, 43);
                color: white;
                justify-content: center;
            }
        </style>
    </head>
    <body>
        <div class="header">
            <h1 align="center" style="margin-top: 0;">KONTROL SERVO</h1>
        </div>
        <div class="slider">
            <input type="range" min="0" max="180" value="90" id="speedSlider">
            &nbsp;
            <p id="speedValue">90</p>
        </div>
    </body>
    <script>
        let slider = document.getElementById("speedSlider");
        let output = document.getElementById("speedValue");
        slider.onchange = function() {
            output.innerHTML = this.value;
            fetch("/speed?value=" + this.value)
        }
    </script>
</html>
)rawliteral";

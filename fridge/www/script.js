
    function update(data)
    {
        $("i").innerHTML = data.i;
        $("A").innerHTML = data.A;
        $("B").innerHTML = data.B;
        $("P").innerHTML = data.P;
        $("V").innerHTML = data.V;
        $("Z").innerHTML = data.Z;
        if (data.aname)
        {
            $("Aname").innerHTML = data.aname;
        }
        if (data.bname)
        {
            $("Bname").innerHTML = data.bname;
        }
        
        if (data.D == 0)
        {
            $("D").innerHTML = "Zavřeno";
        }
        else
        {
            $("D").innerHTML = "Otevřeno";
        }   
        $("timestamp").innerHTML = data.time;
    }
    function $(id)
    {
        return document.getElementById(id);
    }
    //setInterval(update, 1000);
    update({
        i: 11.45,
        A: 12.45,
        B: 13.45,
        P: 14.45,
        V: 15.45,
        Z: 16.45,
        D: 0
    });
    var lastUpdate = +new Date();
    function process(data) 
    {
        data = JSON.parse(data);
        if (!data.value) return;
        update(data.value);
        lastUpdate = +new Date();
        setTimeout(send, 333);
    }
    function send()
    {
        var script = document.createElement("script");
        script.src = "/data/get?jsonp=process";
        document.body.appendChild(script);
        document.body.removeChild(script);
    }
    setInterval(function () {
        if (lastUpdate - new Date() > 5000)
        {
            send();
        }
    })
    send();
  

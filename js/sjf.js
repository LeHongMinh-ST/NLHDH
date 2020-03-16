$(document).ready(function() {

    var i, j;

    //Giải thuật SJF
    $(".process_sbm").click(function(event) {
        $(".result").hide()
        var process = $("#process").val();
        if (process < 2) {
            alert('Số tiến trình phải lớn hơn 2');
            return;
        }
        $("tbody tr").remove();
        if (process > 0) {
            for (i = 1; i <= process; i++) {
                let row = "<tr id=" + 'row' + i + "><th> P" + i + "</th> <td><form><input id=" + 'arival' + i + "></from></td> <td><form><input id = " + 'burst' + i + "></from></td> </tr>";
                var a = $(".a").append(row);
                $("tr th").attr("scope", "row");
                $("input").attr("type", "number");
            }

            $(".sz").show();
        }

        $('.result-btn').click(function(event) {
            $("ul li").empty();
            $(".wait_avg").empty();

            var timeout = 0;
            var sum = 0;
            var process_array = new Array();
            for (i = 1; i <= process; i++) {
                var processObject = new Object();

                processObject.name = "P" + i;
                processObject.arival = $('#arival' + i).val();
                processObject.burst = $('#burst' + i).val();

                process_array.push(processObject);
            }


            let realTime = new Array();
            for (i = 0; i < process; i++) {
                realTime.push(process_array[i].burst);
            }



            let complete = 0,
                t = 0,
                min = Number.MAX_VALUE,
                shortest = 0,
                finishTime, check = false;

            while (complete != process) {
                for (j = 0; j < process; j++) {
                    if ((process_array[j].arival <= t) && (realTime[j] < min) && realTime[j] > 0) {
                        min = realTime[j];
                        shortest = j;
                        check = true;
                    }
                }

                if (check == false) {
                    t++;
                    continue;
                }

                realTime[shortest]--;
                min = realTime[shortest];
                if (min == 0) {
                    min = Number.MAX_VALUE;
                }

                if (realTime[shortest] == 0) {
                    complete++;
                    check = false;

                    finishTime = t + 1;

                    process_array[shortest].wait = finishTime - process_array[shortest].burst - process_array[shortest].arival;

                    if (process_array[shortest].wait < 0) process_array[shortest].wait = 0;
                }

                t++;
            }

            console.log(process_array);

            for (i = 0; i < process; i++) {
                let row = "<li> " + process_array[i].name + " = " + process_array[i].wait + "s </li>"
                $("ul").append(row);
                sum = sum + process_array[i].wait
            }
            var avg = sum / process;

            $(".wait_avg").append("Thời gian chờ đợi trung bình = " + avg + "s");
            $(".result").show();
        })
    })



})
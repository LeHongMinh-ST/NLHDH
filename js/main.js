$(document).ready(function() {

    var i, j;

    //Giải thuật SJF
    $(".process_sbm").click(function(event) {
        var process = $("#process").val();
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

            for (i = 0; i < process; i++) {


                //Sắp xếp các tiến trình
                if (process_array[i].arival >= timeout) {
                    for (j = i + 1; j < process; j++) {
                        if (process_array[j].arival < process_array[i].arival || process_array[j].arival == process_array[i].arival && process_array[j].burst < process_array.burst) {
                            let temp = process_array[i];
                            process_array[i] = process_array[j];
                            process_array[j] = temp;
                        }
                    }
                } else {
                    for (j = i + 1; j < process; j++) {
                        if ((process_array[j].burst < process_array[i].burst || process_array[j].burst == process_array[i].burst && process_array[j].arival < process_array.arival) && process_array[j] <= timeout) {
                            let temp = process_array[i];
                            process_array[i] = process_array[j];
                            process_array[j] = temp;
                        }
                    }
                }

                //Tính thời gian bắt đầu và kết thúc mỗi tiến trình

                if (i == 0) {
                    process_array[i].start = process_array[i].arival;
                } else {
                    if (process_array[i].arival <= process_array[i - 1].end) {
                        process_array[i].start = process_array[i - 1].end;
                    } else {
                        process_array[i].start = process_array[i].arival;
                    }
                }
                process_array[i].end = Number(process_array[i].start) + Number(process_array[i].burst);


                //tính thời gian chờ
                process_array[i].wait = process_array[i].start - process_array[i].arival;
                timeout = process_array[i].end;
            }

            for (i = 0; i < process; i++) {
                j = i + 1;
                let row = "<li> P" + j + " = " + process_array[i].wait + " </li>"
                $("ul").append(row);
                sum = sum + process_array[i].wait
            }
            var avg = sum / process;

            $(".wait_avg").append(avg + "s");
            $(".result").show();
        })
    })



})
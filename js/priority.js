$(document).ready(function() {
    var i, j;
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
                let row = "<tr id=" + 'row' + i + "><th> P" + i + "</th> <td><form><input id=" + 'burst' + i + "></from></td> <td><form><input id = " + 'priority' + i + "></from></td> </tr>";
                var a = $(".a").append(row);
                $("tr th").attr("scope", "row");
                $("input").attr("type", "number");
            }
            $(".sz").show();
        }

        $('.result-btn').click(function(event) {
            $("ul li").empty();
            $(".wait_avg").empty();


            var process_array = new Array();
            for (i = 1; i <= process; i++) {
                var processObject = new Object();

                processObject.name = "P" + i;
                processObject.burst = $('#burst' + i).val();
                processObject.priority = $('#priority' + i).val();

                process_array.push(processObject);
            }

            for (i = 0; i < process; i++) {
                for (j = i + 1; j < process; j++)
                    if (process_array[i].priority == process_array[j].priority) {
                        alert('Giá trị ưu tiên bị trùng !');
                        return;
                    }
            }

            for (i = 0; i < process; i++) {
                let min = i;
                for (j = i + 1; j < process; j++) {
                    if (process_array[j].priority < process_array[min].priority) min = j;
                }
                if (min != i) {
                    let temp = process_array[i];
                    process_array[i] = process_array[min];
                    process_array[min] = temp;
                }
            }

            process_array[0].wait = 0;

            let sum = 0;
            for (i = 1; i < process; i++) {
                process_array[i].wait = 0;
                for (j = 0; j < i; j++) process_array[i].wait += Number(process_array[j].burst);
                sum += process_array[i].wait;
            }

            let avg = sum / process;

            for (i = 0; i < process; i++) {
                let row = "<li> " + process_array[i].name + " = " + process_array[i].wait + "s </li>"
                $("ul").append(row);
            }

            $(".wait_avg").append("Thời gian chờ đợi trung bình = " + avg + "s");
            $(".result").show();
        });
    })

});
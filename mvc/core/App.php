<?php
require_once "./mvc/core/Controllers.php";
class App extends Controllers
{
    protected $mod;
    protected $act;
    protected $prarams =[];

    public function __construct()
    {
        $arr = $this->UrlProcess();

        $this->mod = isset($arr[0])?$arr[0]:'';
        $this->act = isset($arr[1])?$arr[1]:'';
        $this->prarams = $arr ? array_values($arr) : [];
    }

    public function action()
    {
        switch ($this->mod)
        {
            case 'post':

                $controller_obj = $this->controller('PostController');
                switch ($this->act)
                {
                    case 'test':
                        $controller_obj->test($this->prarams);
                        break;
                }
                break;
            default:
                break;
        }
    }

    public function UrlProcess(){
        if(isset($_GET["url"])){
            $url = $_GET["url"];
            $url = $url[strlen($url)-1] == "/" && strlen($url) != 1 ? $url : $url . "/";
            return explode("/",filter_var(trim($url)));
        }
        return [""];
    }
}
?>

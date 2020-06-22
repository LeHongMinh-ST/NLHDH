<?php
require_once "./mvc/core/Controllers.php";

class App extends Controllers
{
    protected $mod;
    protected $act;


    public function __construct()
    {

        $this->mod = (isset($_GET['mod']) ? $_GET['mod'] : '');
        $this->act = (isset($_GET['act']) ? $_GET['act'] : 'list');

    }

    public function action()
    {
        switch ($this->mod) {
            case 'post':

                $controller_obj = $this->controller('PostController');
                switch ($this->act) {
                    case 'test':
                        $controller_obj->test();
                        break;
                }
                break;
            default:
                break;
        }
    }
}

?>

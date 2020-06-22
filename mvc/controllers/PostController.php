<?php

class PostController extends controllers
{
    protected $post;

    public function test($arr=[])
    {
        $this->post = $this->models('Post');

        $arr = ['1','2','3'];
        $data = [
            'views' => 'posts/index',
            'minh' => "đây là trang index của minh",
            'post' => $this->post->all(),
            'arr'=> $arr
        ];

        $this->views('layouts/master', $data);
    }
}
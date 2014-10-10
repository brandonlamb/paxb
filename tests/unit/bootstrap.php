<?php

define('ROOT_PATH', dirname(dirname(__FILE__)));
error_reporting(E_ALL);
require_once 'debug.php';

if (file_exists(\ROOT_PATH . '/../vendor/autoload.php')) {
    $classLoader = require_once \ROOT_PATH . '/../vendor/autoload.php';
    $classLoader->add('PAXB\\Tests\\', __DIR__ . '/');
    unset($classLoader);
}

if (file_exists(\ROOT_PATH . '/autoload.php')) {
    require_once \ROOT_PATH . '/autoload.php';
}

define('START_TIME', microtime(true));

function class = get_class(score)
    if (score > 568)
        class = 2;%表示困难
    elseif score > 447
        class = 1;%表示中等
    else
        class = 0;%表示简单
    end

end
%输入得分，输出等级
    
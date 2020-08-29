.class public Lru/nechta/lab3/one;
.super Landroid/app/Activity;
.source "one.java"


# direct methods
.method public constructor <init>()V
    .locals 0

    .prologue
    .line 14
    invoke-direct {p0}, Landroid/app/Activity;-><init>()V

    return-void
.end method


# virtual methods
.method protected onCreate(Landroid/os/Bundle;)V
    .locals 2
    .param p1, "savedInstanceState"    # Landroid/os/Bundle;

    .prologue
    .line 17
    invoke-super {p0, p1}, Landroid/app/Activity;->onCreate(Landroid/os/Bundle;)V

    .line 18
    const v1, 0x7f030001

    invoke-virtual {p0, v1}, Lru/nechta/lab3/one;->setContentView(I)V

    .line 19
    const v1, 0x7f050001

    invoke-virtual {p0, v1}, Lru/nechta/lab3/one;->findViewById(I)Landroid/view/View;

    move-result-object v0

    check-cast v0, Landroid/widget/ImageView;

    .line 20
    .local v0, "img":Landroid/widget/ImageView;
    const v1, 0x7f020006

    invoke-virtual {v0, v1}, Landroid/widget/ImageView;->setImageResource(I)V

    .line 21
    return-void
.end method
